#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<pair<int,int>> seg;


int main(){
    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;++i){
        cin>>x>>y;
        seg.emplace_back(make_pair(y,x));


    }

    sort(seg.begin(),seg.end());

    int cnt=1;
    int last=seg[0].first;
    for(int i=1;i<n;++i){
        if(seg[i].second>=last){
            cnt++;
            last=seg[i].first;
        }
    }
    cout<<cnt<<'\n';

}