#include<iostream>
using namespace std;
int main(){
    long long  a1,a2,n;
    cin>>a1>>a2>>n;
    long long d=a2-a1;
    long long sum=(a1+a1+d*n-d)*n/2;
    cout<<sum<<endl;




}