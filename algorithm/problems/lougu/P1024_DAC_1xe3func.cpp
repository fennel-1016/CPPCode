#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAXN 102
const double eps =1e-8;
double a,b,c,d;
double arr[MAXN<<1];

double res[3];
int res_index=0;

double gety(double x){
    return a*pow(x,3)+b*pow(x,2)+c*x+d;
}   

double getx(double l, double r){
    double length=r-l;
    double mid=(l+r)/2.0;
    if(length<0.001){
        return mid;
    }
   
    if(fabs(gety(mid))<eps){
        return mid;
    }
    if(gety(l)*gety(mid)<0){
        return getx(l,mid);
    }
    else{
        return getx(mid,r);
    }

}


int main(){

    cin>>a>>b>>c>>d;
    arr[0]=gety(-100);

    if(fabs(arr[0])<eps){
        res[res_index++]=arr[0];
    }


    for(int i=-99;i<101;++i){
        arr[i+100]=gety(i);
        if(fabs(arr[i+100])<eps){
            res[res_index++]=double(i);
            continue;
        }

        double t=arr[i+100]*arr[i+99];
        if(t<0.0){
            res[res_index++]=getx(i-1,i);
        }
        
    }
    sort(res,res+3);
  
    printf("%.2f %.2f %.2f\n",res[0],res[1],res[2]);



}