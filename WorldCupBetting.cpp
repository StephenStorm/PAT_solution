//2019.3.22
//start time 20:11
#include<stdio.h>
using namespace std;
int main(){
    char ch[]={'W','T','L'};
    char re[6];
    int i,j=0,tmp,index;
    double a,b,c;
    double result =1;
    for(i=0;i<6;i++) re[i] = ' ';
    for(i=0;i<3;i++){
        scanf("%f%f%f",&tmp,&b,&c);
        index = 0;
        if(tmp<b) {index = 1;tmp = b;}
        if(tmp<c) {index = 2;tmp = c;}
        re[j] = ch[index];
        j+=2;
        result*=tmp;
    }
    for(i=0;i<6;i++) printf("%c",re[i]);
    result=(result*0.65-1)*2;
    printf("%.2f",result);

}
