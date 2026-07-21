#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 200002
int dp[MAXN];

int main(){

    int n;
    cin>>n;
    cin>>dp[0];
    for(int i=1;i<n;++i){
        cin>>dp[i];
        dp[i]=max(dp[i-1]+dp[i],dp[i]);
    }
    int maxv=*max_element(dp,dp+n);
    cout<<maxv<<endl;
    return 0;
}