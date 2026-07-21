#include<iostream>
using namespace std;
int LR(int l,int r){
    while(l<r){
        r-=r&(-r);//不断删去最右侧的1
    }
    return r;
}
int main(){
    int l,r;
    cin>>l>>r;
    cout<<LR(l,r)<<endl;
    return 0;
}