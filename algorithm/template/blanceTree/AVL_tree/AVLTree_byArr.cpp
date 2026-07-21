#include<iostream>
#include<algorithm>
#include<climits>
#define longlong ll 
#define MAXN 10000

int cnt=0;
int head=0;
int key[MAXN];
int height[MAXN];
int left[MAXN];
int right[MAXN];
int count[MAXN];//i的值出现了多次加次数不加节点
int size[MAXN];

void up(int i){
    size[i]=size[left[i]]+size[right[i]]+count[i];
    height[i]=std::max(height[left[i]],height[right[i]])+1;
}

int leftRotate(int i){
    int r=right[i];
    right[i]=left[r];
    left[r]=i;
    up(i);
    up(r);
    return r;
}
int rightRotate(int i){
    int l=left[i];
    left[i]=right[l];
    right[l]=i;
    up(i);
    up(l);
    return l;
}

int maintain(int i){
    int lh=height[left[i]];
    int rh=height[right[i]];
    if(lh-rh>1){
        //LL，优先于LR，满足删除时的一种特殊情况
        if(height[left[left[i]]]>height[right[left[i]]]){
            i=rightRotate(i);
        }
        //LR
        else{
            left[i]=leftRotate(left[i]);
            i=rightRotate(i);
        }
    }
    else if(rh-lh>1){
        //RR
        if(height[left[right[i]]]<height[right[right[i]]]){
            i=leftRotate(i);
        }
        //RL
        else{
            right[i]=rightRotate(right[i]);
            i=leftRotate(i);
        }
    }
    return i;
}
int add(int i,int num){
    if(i==0){//空节点,建树
        key[++cnt]=num;
        count[cnt]=size[cnt]=height[cnt]=1;
        return cnt;
    }
    if(key[i]==num){//已经有这个值了
        count[i]++;
    }
    else if(key[i]>num){
        left[i]=add(left[i],num);
    }
    else{
        right[i]=add(right[i],num);
    }
    up(i);//依据左右节点更新父节点
    return maintain(i);//检查当前结构是否违规
}
void add(int num){//维护根节点的add
    head=add(head,num);
}

//以i为头的树上，比num小的数字的个数
int small(int i,int num){
    if(i==0){
        return 0;
    }
    if(key[i]>=num){
        return small(left[i],num);
    }
    else{
        //左树数量+icount+右树上的个数
        return size[left[i]]+count[i]+small(right[i],num);
    }
}
//比num小的数的个数+1
int rank(int num){

    return small(head,num)+1;
}
//去除当前树的最左边的节点，更新维护树的结构
int removeMostLeft(int i,int mostleft){
    if(i==mostleft){
        //返回最左支的右支编号,如果有
        return right[i];
    }
    else{
        left[i]=removeMostLeft(left[i],mostleft);
        //向上调整，维护i的数据
        up(i);
        //调整平衡
        return maintain(i);
    }
}

int remove(int i,int num){
    if(key[i]<num){
        //赶路，回头记得更新根节点的编号
        right[i]=remove(right[i],num);
    }
    else if(key[i]>num){
        //赶路，回头记得更新根节点的编号
        left[i]=remove(left[i],num);
    }
    else{
        if(count[i]>1){
            //还有库存
            --count[i];
        }
        else{
            if(left[i]==0&&right[i]==0){
                //叶子节点
                return 0;
            }
            else if(left[i]!=0&&right[i]==0){
                //当前节点用其原来的左子结点代替
                i=left[i];
            }
            else if(left[i]==0&&right[i]!=0){
                i=right[i];
            }
            else{
                //左右都不为空
                int mostleft=left[i];
                while(right[mostleft]){
                    mostleft=left[mostleft];
                }
                //更新右子树结构,同时更新根节点信息
                right[i]=removeMostLeft(right[i],mostleft);
                //更新删除节点位置的左右节点，返回mostleft给父节点
                left[mostleft]=left[i];
                right[mostleft]=right[i];
                i=mostleft;
            }
        }
    }
    up(i);
    return maintain(i);
}

void remove(int num){
    //存在num
    if(rank(num)!=rank(num+1)){
        head=remove(head,num);
    }
}

int index(int i,int x){
    //左树的大小比排名高，在左树找
    if(size[left[i]]>=x){
        return index(left[i],x);
    }
    //算上当前还是不够，去右树找排名x-size[left[i]]-count[i]的
    else if(size[left[i]]+count[i]<x){
        return index(right[i],x-size[left[i]]-count[i]);
    }
    //当前值就是
    return key[i];
}
//排名x的值
int index(int x){
    return index(head,x);
}

int pre(int i,int num){
    if(i==0){
        return INT_MIN;
    }
    if(key[i]>=num){
        return pre(left[i],num);
    }
    else if(key[i]<num){
        return std::max(key[i],pre(right[i],num));
    }
}
//查找num的前驱,小于x的值里最大的
int pre(int num){
    return pre(head,num);
}
//大于x的最小的
int past(int i,int num){
    if(i==0){
        return INT_MAX;
    }
    if(key[i]<=num){
        return past(right[i],num);
    }
    else{
        return std::min(key[i],past(left[i],num));
    }
}

int past(int num){
    return past(head,num);
}

void clear(){
    for(int i=1;i<=cnt;++i){
        key[i]=0;
        height[i]=0;
        left[i]=0;
        right[i]=0;
        count[i]=0;
        size[i]=0;
    }
    cnt=0;
    head=0;
}
int main(){
    




}