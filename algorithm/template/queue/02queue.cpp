#include <iostream>
#include <string>
#include <sstream>
#define MAXN 1000000
using namespace std;
class Queue{
private:
    int data[MAXN];
    int f_ind,b_ind;

public:
    Queue():f_ind(0),b_ind(0){}
    void push(int x){
        data[b_ind]=x;
        b_ind=(++b_ind)%MAXN;
        
    }
    void pop(){
        if(f_ind==b_ind){
            cout<<"ERR_CANNOT_POP"<<endl;
        }
        else {
            f_ind=(++f_ind)%MAXN;
        }
    }
    void query(){
        if(f_ind==b_ind){
            cout<<"ERR_CANNOT_QUERY"<<endl;
        }
        else {
            cout<<data[f_ind]<<endl;
        }
    }
    void size(){
        cout<<(b_ind-f_ind+MAXN)%MAXN<<endl;
    }
};

int main(){
    Queue que;
    int n;
    cin>>n;
    for (int i=0;i<n;++i){
        int opt;
        cin>>opt;
        switch (opt){
            case 1:{
                int temp;
                cin>>temp;
                que.push(temp);
                break;
            }
            case 2:que.pop();break;
            case 3:que.query();break;
            case 4:que.size();break;

        }

    }
    return 0;
}