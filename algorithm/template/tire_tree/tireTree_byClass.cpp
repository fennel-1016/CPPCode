#include<iostream>
#include<string>
using namespace std;
#define MAXC 26
#define START_CHAR 'a'//默认为a-z，可以调节
class TrieTree{
    typedef struct TrieNode
    {
        int pass;
        int end;
        TrieNode** nexts;

        TrieNode(){
            pass=0;
            end=0;
            nexts=new TrieNode*[MAXC];
        }
    } TN;

private:
    TrieNode* root;
    
    //递归释放辅助函数
    void del_rest(TrieNode* root){
        if(root==nullptr){
            return;
        }
        for(int i=0;i<MAXC;++i){
            del_rest(root->nexts[i]);
        }
        delete root;
    }
public:
    //构造与析构
    TrieTree(){
        root=new TrieNode();
    }
    ~TrieTree(){
        del_rest(root);
    }

    //插入
    void insert(const string& s){
        int l=s.size();

        TrieNode* cur_node=root;
        cur_node->pass++;//根节点单词数加一
        for(int i=0;i<l;++i){
            int path=s[i]-START_CHAR;
            if(!cur_node->nexts[path]){
                cur_node->nexts[path]=new TN();

            }
            cur_node=cur_node->nexts[path];
            cur_node->pass++;//当前节点被加一
        }
        cur_node->end++;//结尾加一
    }

    //返回单词数量
    int count_words(const string& s){
        int l=s.size();

        TrieNode* cur=root;
        for(int i=0;i<l;++i){
            int path=s[i]-START_CHAR;
            if(!cur->nexts[path]){
                return 0;
            }
            cur=cur->nexts[path];
        }
        return cur->end;
    }

    //返回含有前缀单词的数量
    int count_pre_words(const string& s){
        int l=s.size();

        TrieNode* cur=root;
        for(int i=0;i<l;++i){
            int path=s[i]-START_CHAR;
            if(!cur->nexts[path]){
                return 0;
            }
            cur=cur->nexts[path];
        }
        return cur->pass;
    }


    //删除一次单词
    void erase(const string& s){
        if(count_words(s)==0){
            return ;
        }
        int l=s.size();
        
        TrieNode*cur=root;
        cur->pass--;
        for(int i=0;i<l;++i){

            int path=s[i]-START_CHAR;
            if(--cur->nexts[path]->pass==0){
                del_rest(cur->nexts[path]);
                return ;
            }
            cur=cur->nexts[path];
        }
        cur->end--;
    }
    
};

int main(){
    TrieTree tt;
    tt.insert("apple");
    tt.insert("app");
    cout<<tt.count_words("apple")<<endl;
    cout<<tt.count_pre_words("app")<<endl;
    tt.erase("app");
    cout<<tt.count_pre_words("app")<<endl;
}