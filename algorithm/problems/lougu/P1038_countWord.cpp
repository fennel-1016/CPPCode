#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(){
    string key;
    string article;

    cin>>key;
    for(char& c:key){c=tolower(c);}
    getchar();
    key=' '+key+' ';

    getline(cin,article);
    article=' '+article+' ';
    for(char& c:article){
        c=tolower(c);
    }
    
    if(article.find(key)!=-1){
        int first_index=article.find(key);
        int curr_index=first_index;
        int count=0;
        while(curr_index!=-1){
            count++;
            curr_index=article.find(key,curr_index+1);
        }
        cout<<count<<' '<<first_index<<endl;
        return 0;
    }
    cout<<-1<<endl;

    return 0;
}