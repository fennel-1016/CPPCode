#include<iostream>
#include<algorithm>

using namespace std;
#define MAXN 100001
#define ll long long 
int L=0;
int R=1e9;

int arr[MAXN];
int n,m;

bool check(int x){
    int parts=1;
    ll cur=0;
    for(int i=0;i<=n;++i){
        if(arr[i]>x){
            return false;
        }
        if(cur+arr[i]<=x){
            cur+=arr[i];
        }
        else{
            ++parts;
            cur=arr[i];
        }
    }
    return parts<=m;
}

int main(){

    cin>>n>>m;
    for(int i=1;i<=n;++i){
        cin>>arr[i];
    }

    while (L<=R)
    {
        int mid=(L+R)>>1;
        if(check(mid)){
            R=mid-1;
        }
        else{
            L=mid+1;
        }
    }
    cout<<L<<'\n';
}