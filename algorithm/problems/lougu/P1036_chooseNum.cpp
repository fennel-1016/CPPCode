#include<iostream>
#include<cmath>
#include<vector>
#include<numeric>
using namespace std;
int cnt;

bool is_perimeNum(int n){
    if(n<=1)return false;
    if(n==2||n==3||n==5)return true;
    if(n%2==0||n%3==0||n%5==0){
        return false;
    }
    else{
        int t=int(sqrt(n));
        for(int i=5;i<=t;i+=6){
            if(n%i==0||n%(i+2)==0){
                return false;
            }
        }
    }
    return true;
}

void choose_num(vector<int>& sam,int count,int index,vector<int> cho){
    cho.push_back(sam[index]);

    int n=cho.size();
    int sn=sam.size();
    if(n<count){
        if(count-n+index>=sn){
            return ;
        }
        for(int i=index+1;i<sn;++i){
            choose_num(sam,count,i,cho);
        }
    }
    else if(n==count){
        int sum=accumulate(cho.begin(),cho.end(),0);
        if(is_perimeNum(sum)){
            cnt++;
        }
    } 
    
}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> sample(n);
    int temp;
    for(int i=0;i<n;++i){
        cin>>temp;
        sample[i]=temp;
    }
    for(int i=0;i<=n-k;++i){
        choose_num(sample,k,i,vector<int> ());
    }
    cout<<cnt<<endl;
    return 0;

}