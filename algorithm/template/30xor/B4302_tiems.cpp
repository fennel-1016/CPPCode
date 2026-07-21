#include<iostream>

using namespace std;
int n;
int main(){
    cin>>n;
    int x=0;
    int t;
    for(int i=0;i<n;++i){
        cin>>t;
        x^=t;
    }
    cout<<x<<endl;
    return 0;
}