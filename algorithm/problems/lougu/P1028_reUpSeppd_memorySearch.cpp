#include<iostream>
using namespace std;
#define MAXN 1024
int cnt[MAXN];


int main(){
    int n;
    cin>>n;
    cnt[0]=0;
    cnt[1]=1;
    if(n==1){
        cout<<1<<endl;
        return 0;
    }

    int h=n/2;
    for(int i=2;i<=h;++i){
        int half=i/2;
        cnt[i]++;
        for(int j=1;j<=half;++j){
            cnt[i]+=cnt[j];
        }
    }
    for(int i=1;i<=h;++i){
        cnt[n]+=cnt[i];
    }
    cout<<++cnt[n]<<endl;
    return 0;
}
