//2019.3.30 start time:21:50 AC time 23:00
//�ջ�  �ڽṹ������������ʱ��ʼ����Ч  ���� int score[6]={-2};  �ñ��ʽ����Ч
//����Ҫ���Ҵ��ڵ�����ʱ�������ùؼ���������������Լ��ٱ�������ֲ��һ��ѵ�ʱ��
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct student{
    int id;
    int score[6];
    int total=0;
    int Rank;
    int perNum=0;//���������������
    bool isshown=false;
};
bool cmp(student s1,student s2){
    if(s1.total!=s2.total) return s1.total>s2.total;
    else return s1.perNum==s2.perNum?s1.id<s2.id:s1.perNum>s2.perNum;
}
int main(){
    int n,k,m;
    scanf("%d %d %d",&n,&k,&m);
    vector<int> full(k);
    vector<student> vec(n+1);//id start from 1;
    int i,j;
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++)
            vec[i].score[j]=-2;
    }
    for(i=0;i<k;i++){
        scanf("%d",&full[i]);
    }
    int id,num,grade;
    for(i=1;i<=m;i++){
        scanf("%d %d %d",&id,&num,&grade);
        vec[id].id = id;
        if(grade>vec[id].score[num]) vec[id].score[num]=grade;
        if(grade>-1) vec[id].isshown = true;
    }
    for(i=1;i<=n;i++){
        for(j=1;j<=k;j++){
            if(vec[i].score[j]>0){
                vec[i].total+=vec[i].score[j];
                if(vec[i].score[j]==full[j-1])
                    vec[i].perNum++;
            }
        }
    }
    sort(vec.begin()+1,vec.end(),cmp);
    vec[1].Rank = 1;
    for(i=2;i<=n;i++){
        if(vec[i].total == vec[i-1].total)
            vec[i].Rank = vec[i-1].Rank;
        else
            vec[i].Rank = i;
    }
    for(i=1;i<=n;i++){
        if(vec[i].isshown){
            printf("%d %05d %d",vec[i].Rank,vec[i].id,vec[i].total);
            for(j=1;j<=k;j++){
                if(vec[i].score[j]==-2) printf(" -");
                else{
                    if(vec[i].score[j]==-1) printf(" 0");
                    else printf(" %d",vec[i].score[j]);
                }
            }
            printf("\n");
        }
    }
}
