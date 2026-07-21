#include<iostream>
#include<vector>


using namespace std;
void bubbleSort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n;++i){
        for(int j=0;j<n-1-i;++j){
            if(a[j]>a[j+1]){
                swap(a[j],a[j+1]);      
            }
        }
    }
    return ;
}
void selectSort(vector<int>& a){
    int n=a.size();
    for(int i=0;i<n;++i){
        int minI=i;
        for(int j=i;j<n;++j){
            if(a[minI]>a[j]){
                minI=j;
            }
        }
        swap(a[minI],a[i]);
    }
    return ;
}
void insertSort(vector<int>& a){
    int n=a.size();
    for(int i=1;i<n;++i){
        for(int j=i;j>=1;--j){
            if(a[j-1]>a[j]){
                swap(a[j],a[j-1]);
            }
            else{
                break;
            }
        }
    }
    return ;
}
int main(){

    vector<int> vec{9,2,3,42,3,83,23,8,523,45,3};

    for(int x:vec){
        cout<<x<<' ';
    }
    cout<<endl;
    // bubbleSort(vec);
    // selectSort(vec);
    insertSort(vec);
    for(int x:vec){
        cout<<x<<' ';
    }
    cout<<endl;
    return 0;
}