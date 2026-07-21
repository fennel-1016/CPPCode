#include<iostream>
using namespace std;
#define MAXN 100001
int arr[MAXN];
int pre[MAXN];
int n,m;
int x,y;
int main(){
    cin>>n;
    pre[0]=0;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
        pre[i]=pre[i-1]+arr[i];
    }
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>x>>y;
        cout<<pre[y]-pre[x-1]<<'\n';
    }



    return 0;
}