//相较于类实现不能使用哈希寻路，也存在内存碎片问题
//处理较多字符时可以按位来进行处理
#include<iostream>
#include<string>

using namespace std;
#define MAXL 3000006
#define MAXC 63

int** trieTree;
int* pass;
int* end_;
int cnt=1;//当前已分配使用的内存下标,0不使用,1作为首节点

int get_index(char a){
    if(a<='9'&&a>='0'){
        return a-'0';
    }
    else if(a>='A'&&a<='Z'){
        return a-'A'+10;
    }
    else{
        return a-'a'+36;
    }
}

//插入
void insert(const string& s){
    int cur=1;
    int l=s.size();

    pass[cur]++;//当前树内单词数加一
    for(int i=0;i<l;++i){
        int path=get_index(s[i]);
        if(!trieTree[cur][path]){
            trieTree[cur][path]=++cnt;
        }
        cur=trieTree[cur][path];
        pass[cur]++;
    }
    end_[cur]++;
}



//前缀查询
int count_pre_word(const string& s){
    int cur=1;
    int l=s.size();

    for(int i=0;i<l;++i){
        int path=get_index(s[i]);
        if(!trieTree[cur][path]){
            return 0;
        }
        cur=trieTree[cur][path];
    }
    return pass[cur];
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
    cnt=1;
}

int main(){
    trieTree=new int*[MAXL];
    for(int i=0;i<MAXL;++i){
        trieTree[i]=new int[MAXC];
    }

    pass=new int[MAXL];
    end_=new int[MAXL];

    int T;
    cin>>T;
    for(int i=0;i<T;++i){
        int n,q;
        cin>>n>>q;
        string temp;
        for(int j=0;j<n;++j){
            cin>>temp;
            insert(temp);
        }
        for(int j=0;j<q;++j){
            cin>>temp;
            cout<<count_pre_word(temp)<<endl;
        }

        clear();
    }

}