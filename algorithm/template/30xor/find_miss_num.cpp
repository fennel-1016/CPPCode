#include<iostream>
using namespace std;
int find_miss_num(int* arr,int n){
    int eorall=0,eorhas=0;
    for(int i=0;i<n;++i){
        eorall^=i;
        eorhas^=arr[i];
    }
    eorall^=n;
    return eorall^eorhas;
}
int main(){
    int a[]={0,1,2,3,5,6,7,8};
    cout<<find_miss_num(a,8);
}
