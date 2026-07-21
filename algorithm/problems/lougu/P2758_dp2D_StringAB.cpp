#include<iostream>

using namespace std;
#define MAXN 2024
int dp[MAXN][MAXN];//a前i个字符变成b前j个字符至少要多少步
string a,b;

int main(){
    cin>>a>>b;
    //dp[0]:0---0,第一行默认为0,
    int n=a.size();
    int m=b.size();
    a=' '+a;
    b=' '+b;

    for(int i=0;i<=n;++i){
        dp[i][0]=i;
    }
    for(int j=0;j<=m;++j){
        dp[0][j]=j;
    }

    for(int i=1;i<=n;++i){

        for(int j=1;j<=m;++j){
            if(a[i]==b[j]){
                dp[i][j]=dp[i-1][j-1];
            }
            else{
                dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
            }
        }
    }

    cout<<dp[n][m]<<endl;
}