#include<iostream>
#include<algorithm>
#define MAXN 1024

int dp[MAXN][MAXN];
int main(){
    using namespace std;
    int r;
    cin>>r;
    cin>>dp[1][1];
    for(int i=2;i<=r;++i){
        for(int j=1;j<=i;++j){
            cin>>dp[i][j];
            dp[i][j]+=max(dp[i-1][j-1],dp[i-1][j]);
        }
    }
    int max_val=*max_element(dp[r],dp[r]+1001);
    cout<<max_val<<endl;



}