//2019.3.31
#include<string.h>
#include<stdio.h>
#include<algorithm>
using namespace std;
int main(){
    char dig[21];
    scanf("%s",dig);
    bool flag=false;
    if(dig[0]>'4') {
        printf("No\n");
        flag = true;
    }
    int len = strlen(dig);
    char num[len]={0},save[len];
    int i=len,tmp;
    while(i--){
        tmp = (dig[i]-48)+(dig[i]-48);
        num[i]+=tmp%10;
        if(i>0)  num[i-1]+=tmp/10;
    }
    for(i=0;i<len;i++) num[i]+=48;
    num[len] = 0;
    if(flag)
        {printf("1%s",num);return 0;}
    strcpy(save,num);
    sort(dig,dig+len);
    sort(num,num+len);
    if(strcmp(dig,num)==0)
        printf("Yes\n");
    else printf("No\n");
    printf("%s",save);
    return 0;
}
