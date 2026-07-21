#include<iostream>
#include<vector>

using namespace std;
void heapInsert(vector<int>&a,int i);
void heapDown(vector<int>& a,int i,int size);
void heapSort1(vector<int>&a);

int main(){
    vector<int> vec{23,45,1,45652,45,5,452,5,3,3,8,78};
    heapSort1(vec);
    for(int x:vec){
        cout<<x<<' ';
    }
    return 0 ;
}
//大顶堆，在某个位置i更改或是插入一个值，这时更新数组a,向上调整数组
void heapInsert(vector<int>&a,int i){
    while(i>0){
        if(a[i]<=a[(i-1)/2])
            break;
        swap(a[i],a[(i-1)/2]);
        i=(i-1)/2; 
    }
}

//向下调整数组
void heapDown(vector<int>& a,int i,int size){
    int l=i*2+1;
    while(i<size){
        int biggerIndex=(l+1<size&&a[l]<a[l+1])?l+1:l;//最大值索引
        if(l>=size||a[i]>=a[biggerIndex]){//没有孩子，比孩子大
            break;
        }
        else{
            swap(a[i],a[biggerIndex]);
            i=biggerIndex;
            l=i*2+1;
        }
    }
}

void heapSort1(vector<int>&a){
    int n=a.size();
    for(int i=0;i<n;++i){
        heapInsert(a,i);
    }

    cout<<"\n";
    for(int x:a){
        cout<<x<<' ';
    }
    cout<<"\n";

    int size=n;
    while(size>1){
        swap(a[0],a[--size]);
        heapDown(a,0,size);
        for(int x:a){
        cout<<x<<' ';
        }
        cout<<"\n";

    }
    return ;
}