#include <iostream>
#include <string>

using namespace std;

#define MAXN 100002
#define ll long long 
ll M ;

ll* arr;
ll* sum;
ll* add;
ll* mul;

void up(int i){//当前节点信息
    //处理方式为sum
    sum[i]=(sum[i<<1]+sum[i<<1|1])%M;
}
void mullazy(int i,ll v){
    v%=M;
    sum[i]=(sum[i]*v)%M;
    mul[i]=(mul[i]*v)%M;
    add[i]=(add[i]*v)%M;
}
void addlazy(int i ,ll v,int n){
    v%=M;
    sum[i]=(sum[i]+(ll)(n%M)*v%M)%M;
    add[i]=(add[i]+v)%M;
}

void down(int i,int ln,int rn){
    if(mul[i]!=1){
        mullazy(i<<1,mul[i]);
        mullazy(i<<1|1,mul[i]);
        mul[i]=1;
    }
    if(add[i]){
        addlazy(i<<1,add[i],ln);
        addlazy(i<<1|1,add[i],rn);
        add[i]=0;
    }
    
}
void build(ll* a,int l,int r,int i){
    //a 外界数组  l左边界  r有边界 i data的当前节点
    if(l==r){
        sum[i]=a[l]%M;
    }
    else{
        int mid=(l+r)>>1;
        build(a,l,mid,i<<1);
        build(a,mid+1,r,i<<1|1);
        up(i);//子结点运行完成后再补充父节点
    }
}

    
//query(2,7,1,8,1)
ll query(int jobl,int jobr,int l,int r,int i){//返回区间sum值
    if(jobl<=l&&jobr>=r){//在但前便利区间lr下，直接使用当前区间的data【i】
        return sum[i];
    }

    int mid=(l+r)>>1;//将当前区间分为两部分
    down(i,mid-l+1,r-mid);

    ll ans=0;
    if(jobl<=mid){//是否需要左半部分
        ans+=query(jobl,jobr,l,mid,i<<1);
    }
    if(jobr>mid){//是否需要右边部分
        ans+=query(jobl,jobr,mid+1,r,i<<1|1);
    }
    return ans%M;
}
//add()
void f_add(int jobl,int jobr,ll jobv,int l,int r,int i){
    if(jobl<=l&&jobr>=r){
        addlazy(i,jobv,r-l+1);
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
void f_mul(int jobl,int jobr,ll jobv,int l,int r,int i){
    if(jobl<=l&&jobr>=r){
        mullazy(i,jobv);
    }
    else{
        
        int mid=(l+r)>>1;

        down(i,mid-l+1,r-mid);

        if(jobl<=mid){
            f_mul(jobl,jobr,jobv,l,mid,i<<1);
        }
        if(jobr>mid){
            f_mul(jobl,jobr,jobv,mid+1,r,i<<1|1);
        }
        up(i);//更新当前的节点值
    }
}

int main(){
    ios::sync_with_stdio(false);

    int size=MAXN<<2;
    arr=new ll[MAXN];
    sum=new ll[size];
    add=new ll[size];
    mul=new ll[size];

    for(int i=0;i<size;++i){
        mul[i]=1;
        add[i]=0;
        sum[i]=0;
    }

    int n,q;
    cin>>n>>q>>M;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }

    build(arr,1,n,1);
    int opt,x,y;
    ll k;
    for(int i=0;i<q;++i){
        cin>>opt>>x>>y;
        switch (opt){
            case 1:{
                cin>>k;
                f_mul(x,y,k,1,n,1);
                break;
            }
            case 2:{
                cin>>k;
                f_add(x,y,k,1,n,1);
                break;
            }
            case 3:{
                cout<<query(x,y,1,n,1)<<'\n';
                break;
            }
            default:
                break;
        }
    }
    return 0;
}