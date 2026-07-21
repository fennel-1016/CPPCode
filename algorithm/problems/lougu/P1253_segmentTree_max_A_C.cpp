//求和线段树，类实现，更改方式为区间重置和添加
//优先级的问题，重置会清除当前的累加，所以优先级更高
//3个标记数组用于完成对应的标记
//lazy函数分别使用对应的lazy方法
//down函数处理时先处理update，如果有add那说明add的lazy一定在现有的update后，因为updtae会清零add
#include <iostream>
#include<string>
#include<algorithm>
#include<climits>
using namespace std;

#define MAXN 1000002
#define ll long long 

ll arr[MAXN];//原始数据

class SegmentTree{
private:
    ll* max_;//节点i对应的区间的和
    ll* add;
    ll* change;//节点i对应的区间的应该修改的值
    bool* update;//节点i对应的区间是否应该修改
    int size;//上述两个数组的大小，一般为四倍的数据量
public:
    //初始化内存申请
    SegmentTree(int n){
        size=n<<2;
        max_=new ll[size];
        add=new ll[size];
        change=new ll[size];
        update=new bool[size];
    }
    //建树
    void build(ll* a,int l,int r,int i){
        //a 外界数组  l左边界  r有边界 i data的当前节点
        //单点赋值
        if(l==r){
            max_[i]=a[l];
        }
        //父节点递归子结点
        else{
            int mid=(l+r)>>1;
            build(a,l,mid,i<<1);
            build(a,mid+1,r,i<<1|1);
            //子结点运行完成后再补充父节点
            up(i);
        }
    }
    
    //query(2,7,1,8,1)
    //返回区间jobl，jobr的sum值，本质是求其分为对应已存储的区间各自sum的和
    ll query(int jobl,int jobr,int l,int r,int i){
        //在当前遍历区间lr下，直接使用当前区间的data【i】
        if(jobl<=l&&jobr>=r){
            return max_[i];
        }

        int mid=(l+r)>>1;//细化最小长度
        //求和前由于细化所以需要将懒信息下发
        down(i);

        //结果等于分的区间之和
        ll ans=LONG_LONG_MIN;
        if(jobl<=mid){//是否需要左半部分
            ans=max(ans,query(jobl,jobr,l,mid,i<<1));
        }
        if(jobr>mid){//是否需要右边部分
            ans=max(ans,query(jobl,jobr,mid+1,r,i<<1|1));
        }
        return ans;
    }
    

    void reset(int jobl,int jobr,ll jobv,int l,int r,int i){
        if(jobl<=l&&jobr>=r){
            setlazy(i,jobv);
        }
        else{
            
            int mid=(l+r)>>1;

            //下发et
            down(i);

            if(jobl<=mid){
                reset(jobl,jobr,jobv,l,mid,i<<1);
            }
            if(jobr>mid){
                reset(jobl,jobr,jobv,mid+1,r,i<<1|1);
            }
            //懒更新完成之后更新父节点的值
            up(i);//更新当前的节点值
        }
    }
    void add_(int jobl,int jobr,ll jobv,int l,int r,int i){
        if(jobl<=l&&jobr>=r){
            addlazy(i,jobv);
        }
        else{
            
            int mid=(l+r)>>1;

            //下发add
            down(i);

            if(jobl<=mid){
                add_(jobl,jobr,jobv,l,mid,i<<1);
            }
            if(jobr>mid){
                add_(jobl,jobr,jobv,mid+1,r,i<<1|1);
            }
            //懒更新完成之后更新父节点的值
            up(i);//更新当前的节点值
        }
    }
    void setlazy(int i ,ll v){
        max_[i] = v;
        change[i]=v;
        update[i]=true;
        add[i]=0;

    }
    void addlazy(int i,ll v ){
        max_[i]+=v;
        add[i]+=v;
    }
    void up(int i){//依据子结点求解更新父节点
        //处理方式为sum
        max_[i]=max(max_[i<<1],max_[i<<1|1]);
    }
    void down(int i){
        if(update[i]){
            setlazy(i<<1,change[i]);
            setlazy(i<<1|1,change[i]);
            update[i]=false;
        }
        if(add[i]){
            addlazy(i<<1,add[i]);
            addlazy(i<<1|1,add[i]);
            add[i]=0;
        }
    }
};
int main(){

    ios::sync_with_stdio(false);

    int n,q;
    cin>>n>>q;

    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    SegmentTree sgt(MAXN);
    sgt.build(arr,1,n,1);

    int opt,l,r,x;
    for(int i=0;i<q;++i){
        cin>>opt>>l>>r;
        switch(opt){
            case 1:{
                cin>>x;
                sgt.reset(l,r,x,1,n,1);
                break;
            }
            case 2:{
                cin>>x;
                sgt.add_(l,r,x,1,n,1);
                break;
            }   
            case 3:{
                cout<<sgt.query(l,r,1,n,1)<<'\n';
                break;
            }
        }

    }

    return 0;
}