#include<iostream>
using namespace std;

#define MAXN 24
#define ll long long

ll dp[MAXN][MAXN];
int x,y,a,b;
bool cant_put(int i,int j){
    if((i==a&&j==b)||(i==a-2&&j==b-1)||(i==a-1&&j==b-2)||(i==a+2&&j==b-1)||(i==a+1&&j==b-2)||
        (i==a-2&&j==b+1)||(i==a-1&&j==b+2)||(i==a+2&&j==b+1)||(i==a+1&&j==b+2)){
            return true;
        }
        
    return false;
}
int main(){
    
    cin>>x>>y>>a>>b;

    ++x;++y;++a;++b;
    for(int i=0;i<=x;++i){
        dp[0][i]=0;
        
    }
    for(int j=0;j<=y;++j){
        dp[j][0]=0;
    }
    
    for(int i=1;i<=x;++i){
        for(int j=1;j<=y;++j){
            if(i==1&&j==1)dp[i][j]=1;
            else if(cant_put(i,j))dp[i][j]=0;
            else{
                dp[i][j]=dp[i-1][j]+dp[i][j-1];
            }
        }
    }
    cout<<dp[x][y]<<endl;
}