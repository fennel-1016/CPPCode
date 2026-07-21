#include<iostream>
#include<string>
#define MAXN 1000000
using namespace std;
class Stack{
private:
    unsigned long long data[MAXN];
    int top_index;

public:
    Stack():top_index(-1){}

    void push(unsigned long long x){
        data[++top_index]=x;
        return ;
    }

    void pop(){
        if(top_index==-1){
            cout<<"Empty"<<endl;
        }
        else{
            top_index--;
        }
        return ;
    }

    void  query(){
        if(top_index==-1){
            cout<<"Anguei!"<<endl;
            return ;
        }
        cout<< data[top_index]<<endl;
        return ;
    }

    void size(){
        cout<<top_index+1<<endl;
        return ;
    }
};
int main(){
    int T,n;
    cin>>T;
    for (int i=0;i<T;++i){
        cin>>n;
        Stack stk;
        string opt;
        for(int j=0;j<n;++j){
            cin>>opt;
            if(opt=="push"){
                unsigned long long  temp;
                cin>>temp;
                stk.push(temp);
            }
            else if(opt=="pop"){
                stk.pop();
            }
            else if (opt=="query"){
                stk.query();
            }
            else if (opt=="size"){
                stk.size();
            }
        }
    }
    return 0;
}