#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    if(n<=0){
        cout<<1<<endl;
        return 0;
    }

    n--;
    n|=n>>1;
    n|=n>>2;
    n|=n>>4;
    n|=n>>8;
    n|=n>>16;

    n++;
    cout<<n<<endl;
    return 0;

}