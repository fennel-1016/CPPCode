#include<iostream>
using namespace std;
#define MAXN 5000001
int arr[MAXN];
int df[MAXN];
int n,m,x,y,k;

int main(){
    cin>>n>>m;
    arr[0]=0;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        df[i]=arr[i]-arr[i-1];
    }

    for(int i=0;i<m;++i){
        cin>>x>>y>>k;
        df[x]+=k;
        df[y+1]-=k;
    }

    arr[1]=df[1]+0;
    int minv=arr[1];
    for(int i=2;i<=n;++i){
        arr[i]=df[i]+arr[i-1];
        minv=min(minv,arr[i]);
    }
    cout<<minv<<'\n';

    return 0;
}