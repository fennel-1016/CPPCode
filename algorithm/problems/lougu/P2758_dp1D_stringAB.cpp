#include<iostream>

using namespace std;
#define MAXN 2024
int dp[MAXN];//a前i个字符变成b前j个字符至少要多少步
string a,b;

int main(){
    cin>>a>>b;
    //dp[0]:0---0,第一行默认为0,
    int n=a.size();
    int m=b.size();
    a=' '+a;
    b=' '+b;

    for(int i=0;i<=m;++i){
        dp[i]=i;
    }
    int pre,temp;
    for(int i=1;i<=n;++i){
        pre=dp[0];
        dp[0]=i;
        for(int j=1;j<=m;++j){
            temp=dp[j];

            if(a[i]==b[j]){
                dp[j]=pre;
                pre=temp;
            }
            else{
                dp[j]=min(min(dp[j-1],dp[j]),pre)+1;
                pre=temp;
            }
        }
    }

    cout<<dp[m]<<endl;
}