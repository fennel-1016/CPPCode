#include<iostream>
#include<vector>
using namespace std;
#define maxn 50004
int help[maxn];//静态优化

void Merge(vector<int>&a,int l,int m,int r);
void MergeSort(vector<int>&a,int l,int r);
void MergeSort2(vector<int>&a ,int l,int r);
int main(){
    vector<int> vec={4,5,6,48,5,852,48,524,45,51,5};
    int n=vec.size();
    MergeSort(vec,0,n-1);
    for(int x:vec){
        cout<<x<<' ';
    }
    return 0;
}
void MergeSort(vector<int>&a,int l,int r){
    if(l==r){
        return;
    }
    int m=(l+r)>>1;
    MergeSort(a,l,m);
    MergeSort(a,m+1,r);
    Merge(a,l,m,r);
    return;
}
void Merge(vector<int>&a,int l,int m,int r){
    int i=l,j=m+1;
    vector<int> temp(r-l+1,0);int n=0;//临时版，也可采用静态空间代替，效率更高
    while(i<=m&&j<=r){
        if(a[i]<a[j])
            temp[n++]=a[i++];
        else
            temp[n++]=a[j++];
    }
    while(i<=m){
        temp[n++]=a[i++];
    }
    while(j<=r){
        temp[n++]=a[j++];
    }
    for(int t=0;t<n;++t){
        a[l+t]=temp[t];
    }
    return ;
}
//------------分界线-----------
void MergeSort2(vector<int>&a ,int l,int r){
    int i=l;int j;int n=r-l+1;//左，右，长
    for(int step=1;step<n;step<<=1){//步长每次乘二
        int m;
        while(i<r){
            m=i+step-1;//中间
            if(m+1>r){//没有右边界
                break;
            }
            else{
                j=min(r,i+2*step-1);//右边界的值
                Merge(a,i,m,r);//合并
                i=j+1;//更新下一次的左边界，为下一组长度为step的数组准备
            }
        }
    }
}
void Merge2(vector<int>&a,int l,int m,int r){
   int i=l,j=m+1;
    int n=l;
    while(i<=m&&j<=r){
        if(a[i]<a[j])
            help[n++]=a[i++];
        else
            help[n++]=a[j++];
    }
    while(i<=m){
        help[n++]=a[i++];
    }
    while(j<=r){
        help[n++]=a[j++];
    }
    for(int t=l;t<n;++t){
        a[t]=help[t];
    }
    return ;
}
