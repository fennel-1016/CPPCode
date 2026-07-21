//相较于类实现不能使用哈希寻路，也存在内存碎片问题
//路径可以使用别的方法简化条数
#include<iostream>
#include<string>

using namespace std;
#define MAXL 100000
#define MAXC 26
#define START_CHAR 'a'

int trieTree[MAXL][MAXC];
int pass[MAXL];
int end_[MAXL];
int cnt=1;//当前已分配使用的内存下标,0不使用,1作为首节点

//插入
void insert(const string& s){
    int cur=1;
    int l=s.size();

    pass[cur]++;//当前树内单词数加一
    for(int i=0;i<l;++i){
        int path=s[i]-START_CHAR;
        if(!trieTree[cur][path]){
            trieTree[cur][path]=++cnt;
        }
        cur=trieTree[cur][path];
        pass[cur]++;
    }
    end_[cur]++;
}

//单词查询
int count_word(const string& s){
    int cur=1;
    int l=s.size();
    
    for(int i=0;i<l;++i){
        int path=s[i]-START_CHAR;
        if(!trieTree[cur][path]){
            return 0;
        }
        cur=trieTree[cur][path];

    }
    return end_[cur];
}

//前缀查询
int count_pre_word(const string& s){
    int cur=1;
    int l=s.size();

    for(int i=0;i<l;++i){
        int path=s[i]-START_CHAR;
        if(!trieTree[cur][path]){
            return 0;
        }
        cur=trieTree[cur][path];
    }
    return pass[cur];

}

//减少一个字符串
void erase(const string &s){
    if(count_word(s)==0){
        return;
    }

    int l=s.size();
    int cur=1;
    pass[cur]--;
    for(int i=0;i<l;++i){
        int path=s[i]-START_CHAR;
        if(--trieTree[cur][path]==0){
            trieTree[cur][path]=0;
            return ;
        }
        cur=trieTree[cur][path];
    }
    end_[cur]--;
}

//方便重复利用，这里清空
void clear(){
    for(int i=0;i<=cnt;++i){
        for(int j=0;j<MAXC;++j){
            trieTree[i][j]=0;
        }
        pass[i]=0;
        end_[i]=0;
    }
}

int main(){



}