//2019.3.26 start time 22:36  ACTime 3.27 9:03
// find the longest suffix
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
    int num,i,minLen=259,j;
    scanf("%d",&num);
    getchar();
    char** lines = new char*[num];
    int *len = new int[num];
    char res[256];
    for(i=0;i<num;i++)  lines[i] = new char[258];
    for(i=0;i<num;i++){
        fgets(lines[i],258,stdin);
        len[i] = strlen(lines[i])-1;
        lines[i][len[i]] = 0;
        //����fgets����������ַ�����ߵĻ��з�������Ҫ�������һ�����з���
        if(minLen>len[i]) minLen = len[i];
    }
    char tmp;
    for(i=1;i<=minLen;i++){
        tmp = lines[0][len[0]-i];
        //printf("%c  ",tmp);
        j = 1;
        while(j<num&&tmp == lines[j][len[j]-i]) j++;
        //����һ��Ҫע���·���˳��  ������j<num��ǰ  �����������λ��
        //���������j=num������½����±������������Խ�磬���߾�����Ϊ����������˴�����ʱ����Ҵ���
        if(j==num)  res[i-1] = tmp;
        else break;
    }
    if(i == 1) printf("nai");
    else
        for(j=i-2;j>=0;j--) printf("%c",res[j]);
}
