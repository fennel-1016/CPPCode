#include<iostream>
#include<algorithm>
#define MAXN 100001
using namespace std;
#define ll long long 
int l=0;
int r=2e6;

int n,L;

int arr[MAXN];
ll pre[MAXN];

bool check(int mid){
    pre[0]=0;
    for(int i=1;i<=n;++i){
        pre[i]=1000LL*arr[i]-mid+pre[i-1];
    }
    ll minv=pre[0];
    for(int i=L;i<=n;++i){
        minv=min(minv,pre[i-L]);
        if(pre[i]>=minv){
            return true;
        }
    }


    return false;
}

int main(){
    
    cin>>n>>L;

    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }
    while(l<=r){
        int mid=(l+r)>>1;

        if(check(mid)){
            l=mid+1;

        }else{
            r=mid-1;
        }
    }
    cout<<r<<'\n';

}