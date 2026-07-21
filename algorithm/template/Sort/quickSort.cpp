#include<iostream>
#include<vector>
#include<random>
using namespace std;

void QuickSort(vector<int>&a,int l,int r,mt19937&gen);
int Partition1(vector<int>&a,int l,int r,int rdNum);
void Partition2(vector<int>&a,int l,int r,int rdNum);

int main(){
    random_device rd;//种子
    mt19937 gen(rd());//随机数生产器，传入种子来开始
    vector<int> vec{7,12,445,5,544,85,22,4,52,45};
    int n=vec.size();
    QuickSort(vec,0,n-1,gen);
    for(int x:vec){
        cout<<x<<' ';
    }
    return 0;
}
void QuickSort(vector<int>&a,int l,int r,mt19937&gen){
    if(l>=r)
    return ;
    uniform_int_distribution<>distr(l,r);//生成指定范围的数
    int rdindex=distr(gen);//随机数，这里是随即索引
    int mid=Partition1(a,l,r,a[rdindex]);
    QuickSort(a,l,mid-1,gen);
    QuickSort(a,mid+1,r,gen);
    return ;
}
int Partition1(vector<int>&a,int l,int r,int rdNum){
    int i=l,j=l;int x0=0;
    while(i<=r){
        if(a[i]<=rdNum){
            swap(a[i],a[j]);
            if(a[j]==rdNum)
                x0=j;
            ++j;
        }                   
        ++i;
    }
    swap(a[j-1],a[x0]);
    return j-1;
}
static int first,last;//等于某个值的起始点，终止点
void QuickSort2(vector<int>&a,int l,int r,mt19937&gen){
    if(l>=r)
    return ;
    uniform_int_distribution<>distr(l,r);//生成指定范围的数
    int rdindex=distr(gen);//随机数，这里是随即索引
    Partition2(a,l,r,a[rdindex]);

    int l2=first;
    int r2=last;
    QuickSort2(a,l,l2-1,gen);
    QuickSort2(a,r2+1,r,gen);
    return ;
}
void Partition2(vector<int>&a,int l,int r,int rdNum){
    first=l;
    last=r;
    int i=l;

    while(i<=last){
        if(a[i]==rdNum){
            ++i;
        }
        if(a[i]<rdNum){
            swap(a[i],a[first]);
            ++first;
            ++i;
        }
        else if(a[i]>rdNum){
            swap(a[i],a[last]);
            --last;
        }
    }
    return ;
}