#include<iostream>
using namespace std;
#define MAXN 1003
int dff[MAXN][MAXN];
int n,m;
int x,y,a,b;
int main(){

    cin>>n>>m;
    for(int i=0;i<m;++i){
        cin>>x>>y>>a>>b;
        dff[x][y]++;
        dff[a+1][y]--;
        dff[x][b+1]--;
        dff[a+1][b+1]++;
    }
    int n1=n+1;
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=n1;++j){
            dff[i][j]+=dff[i-1][j]+dff[i][j-1]-dff[i-1][j-1];
        }
    }

    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            cout<<dff[i][j]<<' ';
        }
        cout<<'\n';
    }


    return 0;
}