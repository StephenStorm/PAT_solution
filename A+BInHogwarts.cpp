//2019.3.27
//不同进制数字相加
//可以说这个题目的处理花费了我很长时间，不过收获巨大，我最大的收获就是灵活利用sccanf函数能够省下很多的时间
//起初我是设想使用循环语句分割处理读入的字符串，但在了解到sscanf的用法后，发现获益匪浅
#include<iostream>
using namespace std;
int main(){
    char str1[20],str2[20];
    scanf("%s %s",str1,str2);
    int first[3],second[3];
    sscanf(str1,"%d.%d.%d",&first[0],&first[1],&first[2]);
    sscanf(str2,"%d.%d.%d",&second[0],&second[1],&second[2]);
    int tmp,res[3],carry;
    tmp = first[2]+second[2];
    carry = tmp/29;
    res[2] = tmp%29;
    tmp = carry+first[1]+second[1];
    carry = tmp / 17;
    res[1] = tmp%17;
    res[0] = first[0]+second[0]+carry;
    printf("%d.%d.%d",res[0],res[1],res[2]);
}
