#include<iostream>
#include<vector>
#include<stack>

using namespace std;
class UnionFind{
    private:
        vector<int> father;
        vector<int> size;
        stack<int> stk;
    public:
        UnionFind(int n){
            father.resize(n);
            size.resize(n,1);
            for(int i=0;i<n;++i){
                father[i]=i;
            }
        }

        int find(int x){
            //扁平化递归实现
            /*
                if(father[x]!=x){
                    father[x]=find(father[x]);
                }
                return father[x];
            */
           
            //扁平换栈实现
            while(x!=father[x]){
                stk.push(x);
                x=father[x];
            }
            while(!stk.empty()){
                father[stk.top()]=x;
                stk.pop();
            }
            return x;

        }

        bool isSameSet(int x,int y){
            return find(x)==find(y);
        }

        void unite(int x,int y){
            int fx=find(x);
            int fy=find(y);
            if(fx==fy){
                return ;
            }
            //小挂大
            if(size[fx]>=size[fy]){
                size[fx]+=size[fy];
                father[fy]=fx;
            }
            else{
                size[fy]+=size[fx];
                father[fx]=fy;
            }
            return ;
        }


};
