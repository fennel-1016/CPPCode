#include<iostream>
using namespace std;
int cnt=0;
void get_Arr(int last);
int main(){
    int n;
    cin>>n;
    get_Arr(n);
    cout<<cnt+1<<endl;
}
void get_Arr(int last){

    if(last!=1){
        int half=last/2;
        for(int i=1;i<=half;++i){
            get_Arr(i);
        }
    }
    cnt++;
    return ;
}
