//2019.3.25 start  time:11:55  end time: 12.10
#include<string.h>
#include<stdio.h>
using namespace std;
int main(){
    int a,b;
    scanf("%d%d",&a,&b);
    int sum1 = a+b;
    int sum = sum1>0?sum1:-sum1;
    char res[15];
    sprintf(res,"%d",sum);
    int len = strlen(res);
    if(sum1<0) {printf("-");}
    if(len<4) {//结果长度小于3位直接输出
        for(int k=0;k<len;k++) printf("%c",res[k]);
        return 0;
    }
    int remainder = len%3;
    int quotient = len/3-1;//减去最后三个要输出的，因为最后3个字符前边没有“，”；
    int  i;
    for(i=0;i<remainder;i++){//输出不够凑成三个的前边几个字符
        printf("%c",res[i]);
    }
    if(remainder>0){
        printf(",");
    }
    while(quotient--){
        for(int j=0;j<3;j++) printf("%c",res[i++]);
        printf(",");
    }
    for(int j=0;j<3;j++) printf("%c",res[i++]);
    return 0;
}
