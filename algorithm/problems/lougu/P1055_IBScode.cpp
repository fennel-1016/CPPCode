#include<iostream>
#include<string>


using namespace std;
int main(){
    string s;
    cin>>s; 
    int sum=0;
    int i=1;
    for(char c:s){
        if(c=='-'||i==10){
            continue;
        }
        sum+=i*(c-'0');
        i++;
    }
    int res=sum%11;
    char end=s[12];


    if(res==10){
        if(end=='X'){
            cout<<"Right"<<endl;
        }
        else{
            s[12]='X';
            cout<<s<<endl;
        }
    }
    else{
        if(res==end-'0'){
            cout<<"Right"<<endl;

        }
        else{
            s[12]=res+'0';
            cout<<s<<endl;
        }
    }
    return 0;
}