#include<iostream>
#include<vector>
using namespace std;
//简化，只保证扁平化，不需要考虑小挂大
class UnionFind{
    private:
        vector<int> father;
    public:
        UnionFind(int n){
            father.resize(n);
            for(int i=0;i<n;++i){
                father[i]=i;
            }
        }

        int find(int x){
            //扁平化递归实现

            if(father[x]!=x){
                father[x]=find(father[x]);
            }
            return father[x];

        }

        bool isSameSet(int x,int y){
            return find(x)==find(y);
        }

        void unite(int x,int y){
            int fx=find(x);
            int fy=find(y);
            if(fx!=fy){
                father[fy]=fx;
            }
          
            return ;
        }


};