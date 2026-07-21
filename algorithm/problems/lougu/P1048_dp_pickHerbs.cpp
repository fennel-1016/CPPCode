#include<iostream>

using namespace std;
#define MAXT 1002
#define MAXM 102

int dp[MAXM][MAXT];//在第i个物品，第j时刻的时间所能拿到的最大价值的物品
int cost[MAXM];
int value[MAXM];

int main(){
    int t,m;
    cin>>t>>m;
    for(int i=1;i<=m;++i){
        cin>>cost[i]>>value[i];
    }


    for(int i=1;i<=m;++i){
        for(int j=0;j<=t;++j){
            //不要i这个物品
            dp[i][j]=dp[i-1][j];
            //如果可以要
            if(j-cost[i]>=0){
                //取不要和花时间要的最大值
                dp[i][j]=max(dp[i][j],dp[i-1][j-cost[i]]+value[i]);
            }
        }
    }
    cout<<dp[m][t]<<endl;
}