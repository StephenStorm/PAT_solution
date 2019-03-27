//2019.3.26 start time:22:15  AC time:22:30
#include<stdio.h>
using namespace std;
int main(){
    int colors[3];
    char res[8]="#000000";
    int k=0;
    char tmp;
    int remainder;
    scanf("%d %d %d",&colors[0],&colors[1],&colors[2]);
    //printf("%d\n",colors[2]);
    for(int i=1;i<6;i+=2){
        for(int j=1;j>=0;j--){//一次求出个位和十位数字并转化成相应的字符
            remainder = colors[k]%13;
            if(remainder <10) tmp = remainder+48;
            else if(remainder == 10) tmp = 'A';
            else if(remainder == 11) tmp = 'B';
            else tmp = 'C';
            colors[k] = colors[k]/13;
            res[i+j] = tmp;
        }
        k++;
    }
    printf("%s",res);
}
