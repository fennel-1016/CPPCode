
//过不了，排序查找太慢
#include<iostream>
#include<set>
using namespace std;

int main(){
    int T,opt,obj;
    cin>>T;
    multiset<int> s;
    for(int i=0;i<T;++i){
        cin>>opt>>obj;
        switch(opt){
            case 1:{
                
                s.insert(obj);
                break;
            }
            case 2:{
                
                if(s.find(obj)!=s.end()){
                    s.erase(s.find(obj));
                }
                break;
            }
            case 3:{
                
                auto it=s.lower_bound(obj);
                int cnt=distance(s.begin(),it);
                cout<<cnt+1<<endl;
                break;
            }
            case 4:{
                //lgK,比较慢，作排序set不太行
                int sz=s.size();
                if(obj<=sz/2){
                    auto it=s.begin();
                    for(int i=1;i<obj;++i){
                        it++;
                    }
                    cout<<*it<<endl;
                }
                else{
                    int step=sz-obj;
                    auto it=s.rbegin();
                    for(int i=0;i<step;++i){
                        it--;
                    }
                    cout<<*it<<endl;
                }
                break;
            }
            case 5:{
                auto it=s.lower_bound(obj);
                --it;
                cout<<*it<<endl;
                break;
            }
            case 6:{
                auto it=s.upper_bound(obj);
                cout<<*it<<endl;
                break;
            }
            default:{
                cout<<"???"<<endl;
            }

        }
    }
}