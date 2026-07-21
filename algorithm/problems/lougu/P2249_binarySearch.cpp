#include<iostream>
using namespace std;
#define MAXN 1000000
int n,m;
int arr[MAXN];
int binary_search(int* a, int x,int l,int r){
    if(l>r){
        return -1;
    }

    int mid=(l+r)>>1;
    if(x==a[mid]){
        if(mid==0)return mid+1;
        if(a[mid-1]!=x)return mid+1;
    }
    if(x<=a[mid]){
        return binary_search(a,x,l,mid-1);
    }
    else{
        return binary_search(a,x,mid+1,r);
    }
}
int main(){

    cin>>n>>m;
    int temp;
    for(int i=0;i<n;++i){
        cin>>temp;
        arr[i]=temp;
    }

    int obj;
    for(int i=0;i<m;++i){
        cin>>obj;
        cout<<binary_search(arr,obj,0,n-1)<<' ';
    }
}
