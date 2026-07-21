#include <iostream>
#include<string>
#define MAXN 100002
#define ll long long 
using namespace std;
ll arr[MAXN];
class SegmentTree{
private:
    ll* data;
    ll* add;
    int size;
public:
    SegmentTree(int n){
        size=n*4;
        data=new ll[size];
        add=new ll[size];
    }
    void build(ll* a,int l,int r,int i){
        //a 外界数组  l左边界  r有边界 i data的当前节点
        if(l==r){
            data[i]=a[l];
        }
        else{
            int mid=(l+r)>>1;
            build(a,l,mid,i<<1);
            build(a,mid+1,r,i<<1|1);
            up(i);//子结点运行完成后再补充父节点
        }
    }
    void up(int i){//当前节点信息
        //处理方式为sum
        data[i]=data[i<<1]+data[i<<1|1];
    }
    
    //query(2,7,1,8,1)
    long query(int jobl,int jobr,int l,int r,int i){//返回区间sum值
        if(jobl<=l&&jobr>=r){//在但前便利区间lr下，直接使用当前区间的data【i】
            return data[i];
        }

        int mid=(l+r)>>1;//将当前区间分为两部分
        down(i,mid-l+1,r-mid);

        long ans=0;
        if(jobl<=mid){//是否需要左半部分
            ans+=query(jobl,jobr,l,mid,i<<1);
        }
        if(jobr>mid){//是否需要右边部分
            ans+=query(jobl,jobr,mid+1,r,i<<1|1);
        }
        return ans;
    }
    //add()
    void f_add(int jobl,int jobr,ll jobv,int l,int r,int i){
        if(jobl<=l&&jobr>=r){
            lazy(i,jobv,r-l+1);
        }
        else{
            
            int mid=(l+r)>>1;

            down(i,mid-l+1,r-mid);

            if(jobl<=mid){
                f_add(jobl,jobr,jobv,l,mid,i<<1);
            }
            if(jobr>mid){
                f_add(jobl,jobr,jobv,mid+1,r,i<<1|1);
            }
            up(i);//更新当前的节点值
        }
    }
    void lazy(int i ,ll v,int n){
        data[i]+=v*n;
        add[i]+=v;
    }
    void down(int i,int ln,int rn){
        if(add[i]!=0){
            lazy(i<<1,add[i],ln);
            lazy(i<<1|1,add[i],rn);
            add[i]=0;
        }
    }
};
int main(){
    int n,m;
    cin>>n>>m;

    ll temp1;
    for(int i=1;i<=n;++i){
        cin>>temp1;
        arr[i]=temp1;
    }

    SegmentTree sgt(MAXN);
    sgt.build(arr,1,n,1);
    
    int opt;
    int x,y;
    for (int i=0;i<m;++i){
        cin>>opt>>x>>y;
        if(opt==1){
            ll k;
            cin>>k;
            sgt.f_add(x,y,k,1,n,1);
        }
        else{
            cout<<sgt.query(x,y,1,n,1)<<endl;
        }
    }


    return 0;
}