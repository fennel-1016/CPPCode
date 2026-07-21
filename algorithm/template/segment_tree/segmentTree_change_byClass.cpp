//求和线段树，类实现，更改方式为区间重置
#include <iostream>
#include<string>

using namespace std;

#define MAXN 100002
#define ll long long 

ll arr[MAXN];//原始数据

class SegmentTree{
private:
    ll* max_;//节点i对应的区间的和
    ll* change;//节点i对应的区间的应该修改的值
    bool* update;//节点i对应的区间是否应该修改
    int size;//上述两个数组的大小，一般为四倍的数据量
public:
    //初始化内存申请
    SegmentTree(int n){
        size=n<<2;
        max_=new ll[size];
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
    long query(int jobl,int jobr,int l,int r,int i){
        //在当前遍历区间lr下，直接使用当前区间的data【i】
        if(jobl<=l&&jobr>=r){
            return max_[i];
        }

        int mid=(l+r)>>1;//细化最小长度
        //求和前由于细化所以需要将懒信息下发
        down(i,mid-l+1,r-mid);

        //结果等于分的区间之和
        long ans=0;
        if(jobl<=mid){//是否需要左半部分
            ans+=query(jobl,jobr,l,mid,i<<1);
        }
        if(jobr>mid){//是否需要右边部分
            ans+=query(jobl,jobr,mid+1,r,i<<1|1);
        }
        return ans;
    }
    

    void reset(int jobl,int jobr,ll jobv,int l,int r,int i){
        if(jobl<=l&&jobr>=r){
            setlazy(i,jobv,r-l+1);
        }
        else{
            
            int mid=(l+r)>>1;

            //下发add
            down(i,mid-l+1,r-mid);

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
    void setlazy(int i ,ll v,int n){
        max_[i] = v*n;
        change[i]=v;
        update[i]=true;
    }
    void up(int i){//依据子结点求解更新父节点
        //处理方式为sum
        max_[i]=max_[i<<1]+max_[i<<1|1];
    }
    void down(int i,int ln,int rn){
        if(update[i]){
            setlazy(i<<1,change[i],ln);
            setlazy(i<<1|1,change[i],rn);
            update[i]=false;
        }
    }
};
int main(){
    

    return 0;
}