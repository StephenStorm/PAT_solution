//2019.3.27 start time:21:20 AC time 22:47
//排序问题
//该题目还留有一个很大的疑问，为什么21行动态申请结构体数组的操作在测试时会造成段错误的结果，即数组访问越界。
//而采用11行这样静态数组则不会造成越界
#include<stdio.h>
#include<algorithm>
using namespace std;
struct student{
    int id;
    int grade[4];
}stu[2000];

int now;
int ranks[1000000][4]={0};
char course[4]={'A','C','M','E'};
bool cmp(student s1,student s2){
    return s1.grade[now]>s2.grade[now];
}

int main(){
    int num1,num2,i,j,tmp,index,minr;
    //student* stu = new student[num1];
    scanf("%d%d",&num1,&num2);
    for(i=0;i<num1;i++){
        scanf("%d %d %d %d",&stu[i].id,&stu[i].grade[1],&stu[i].grade[2],&stu[i].grade[3]);
        stu[i].grade[0] = stu[i].grade[1]+stu[i].grade[2]+stu[i].grade[3];
    }
    for(now=0;now<4;now++){
        sort(stu,stu+num1,cmp);
        ranks[stu[0].id][now]=1;
        for(j=1;j<num1;j++){
            if(stu[j].grade[now]==stu[j-1].grade[now]) ranks[stu[j].id][now] = ranks[stu[j-1].id][now];
            else ranks[stu[j].id][now] = j+1;
        }
    }
    for(i=0;i<num2;i++){
        scanf("%d",&tmp);
        if(ranks[tmp][0] == 0) printf("N/A\n");
        else{
            index=0;
            minr = ranks[tmp][0];
            for(j=1;j<4;j++){
                if(ranks[tmp][j]<minr){
                    minr = ranks[tmp][j];
                    index = j;
                }
            }
            printf("%d %c\n",minr,course[index]);
        }
    }
    //delete[] stu;

}
