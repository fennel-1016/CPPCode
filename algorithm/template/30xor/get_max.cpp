#include<iostream>
int get_max(int a,int b){
    //取c，可能溢出
    int c=a-b;
    //取三个数的符号的相反号0负1正
    int sa=1-((a>>31)&1);
    int sb=1-((b>>31)&1);
    int sc=1-((c>>31)&1);


    //掩码选择
    //ab符号是否不同
    int diffAB=sa^sb;
    //阿布符号是否相同
    int sameAB=diffAB^1;
    //返回A ：符号相同直接就返回a的符号，不同返回c差的符号
    //0表示负数，1表示正数
    //如果符号相同不会溢出，a>b sc为1，b>a sc为0，则returnA对应为1和0
    //符号不同会产生溢出，这时c没有参考价值，考虑a为正则returnA为1，为负则为0
    int returnA=diffAB*sa+sameAB*sc;
    //返回A就不返回B，两者互斥
    int returnB=returnA^1;
    //+号两边返回一边，另一边是0
    return a*returnA+b*returnB;
}
using namespace std;
int main(){
    int a=1,b=2;
    cout<<a<<' '<<b<<' '<<get_max(a,b)<<endl;
    a=-1;b=-2;
    cout<<a<<' '<<b<<' '<<get_max(a,b)<<endl;

    a=-2;b=3;
    cout<<a<<' '<<b<<' '<<get_max(a,b)<<endl;
    a=3;b=-1;
    cout<<a<<' '<<b<<' '<<get_max(a,b)<<endl;


}
