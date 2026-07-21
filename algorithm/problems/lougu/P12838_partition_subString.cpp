#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;
string s;
vector<vector<int>> pos(26,vector<int>());



int main(){
    
    cin>>s;
    s=' '+s;
    int n=s.size();
    for(int i=1;i<n;++i){
        pos[s[i]-'a'].push_back(i);
    }


    int m,la,ra,lb,rb;
    
    cin>>m;
    for(int i=0;i<m;++i){
        cin>>la>>ra>>lb>>rb;
        vector<pair<int,int>> sub1,sub2;
        for(int i=0;i<26;++i){
            auto it=lower_bound(pos[i].begin(),pos[i].end(),la);
            if(it!=pos[i].end()&&*it<=ra){
                sub1.push_back(make_pair(*it,i));
            }
        }
        for(int i=0;i<26;++i){
            auto it =lower_bound(pos[i].begin(),pos[i].end(),lb);
            if(it!=pos[i].end()&&*it<=rb){
                sub2.push_back(make_pair(*it,i));
            }
        }
        
        sort(sub1.begin(),sub1.end());
        sort(sub2.begin(),sub2.end());


        int len1=sub1.size();
        int len2=sub2.size();
        int com=min(len1,len2);

        int df=abs(len2-len1);
        for(int i=0;i<com;++i){
            if(sub1[i].second!=sub2[i].second){
                ++df;
            }
        }
        cout<<df<<'\n';
    
    }


}