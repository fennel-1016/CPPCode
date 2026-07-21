#include <iostream>

using namespace std;
#define ll long long 

#define MAXT 10000002
#define MAXM 10002

ll dp[MAXT];
int cost[MAXM];
int value[MAXM];


int main(){

    int t,m;
    cin>>t>>m;

    for(int i=1;i<=m;++i){
        cin>>cost[i]>>value[i];
    }

    //dp【0】更新完一轮后所有时刻最大收益为0
    //从第一个物品开始，从左到右进行更新，
    for(int i=1;i<=m;++i){
        for(int j=cost[i];j<=t;++j){
            //    复用上一轮的j-1     这一轮的j-cost[i]
            dp[j]=max(dp[j],dp[j-cost[i]]+value[i]);

        }
    }
    cout<<dp[t]<<endl;
}



// for(int i=1;i<=m;++i){
//         for(int j=0;j<=t;++j){
//             //不要i这个物品
//             dp[i][j]=dp[i-1][j];
//             //如果可以要
//             if(j-cost[i]>=0){
//                 //取不要和花时间要的最大值,区别是拿了之后可以在i这个物品上继续叠，
//                  //之前i拿了之后就不会继续叠了，数值在拿了之后那个节点开始往后就不变了
//                 dp[i][j]=max(dp[i][j],dp[i][j-cost[i]]+value[i]);
//             }
//         }
//     }
//     cout<<dp[m][t]<<endl;