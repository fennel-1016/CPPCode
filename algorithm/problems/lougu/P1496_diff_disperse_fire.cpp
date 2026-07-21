#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


vector<pair<int ,int>> seg;//输入数据
vector<int> xs;//映射数组
vector<bool>cover;//覆盖区间标记数组
int n;

int main(){
    cin>>n;
    int x,y;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        seg.push_back(make_pair(x,y));
        xs.push_back(x);
        xs.push_back(y);
    }

    sort(xs.begin(),xs.end());
    xs.erase(unique(xs.begin(),xs.end()),xs.end());

    cover.resize(xs.size(),false);
    for(auto p:seg){
        int L=lower_bound(xs.begin(),xs.end(),p.first)-xs.begin();
        int R=lower_bound(xs.begin(),xs.end(),p.second)-xs.begin();
        for(int i=L;i<R;++i){
            cover[i]=true;
        }
    }

    long long ans=0;
    int len=cover.size()-1;
    for(int i=0;i<len;++i){
        if(cover[i]){
            ans+=xs[i+1]-xs[i];
        }
    }


    cout<<ans<<'\n';
    return 0;
}