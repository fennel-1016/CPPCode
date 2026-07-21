#include<iostream>

using namespace std;
int cnt;
void splitNum(int last,int rest_n,int rest){
    if(rest<1){
        return ;
    }
    if(rest_n==1){
        if(rest>last){
            return ;
        }
        else{
            cnt++;
            return ;
        }
    }
    else{
        for(int i=last;i>0;--i){
            splitNum(i,rest_n-1,rest-i);
        }
    }


}
int main(){
    int n,k;
    cin>>n>>k;
        splitNum(n,k,n);
    
    
    cout<<cnt<<endl;
}
