//2019.3.30 start time: 17:45 ACtime 18:14
//��ͬ�ؼ�������
//�������ջ�
//�����ջ����ڷ����� cin��cout�������������������ʱ�ǳ���ʱ��Ч�ʲ���scanf��printf��
//ͬʱ������scanf����������%s  ��������string��
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
struct record{
    string id;
    string name;
    int grade;
};

bool cmp1(record r1,record r2){
    //��idΪ�ؼ���
    return r1.id<r2.id;
}
bool cmp2(record r1,record r2){
    //nameΪ���ؼ��֣�idΪ���ؼ���
    return r1.name==r2.name?r1.id<r2.id:r1.name<r2.name;
}
bool cmp3(record r1,record r2){//���
    return r1.grade==r2.grade?r1.id<r2.id:r1.grade<r2.grade;
}
int main(){
    int num,c;
    scanf("%d %d",&num,&c);
    vector<record> stu(num);
    int i;
    for(i=0;i<num;i++){
        cin>>stu[i].id>>(stu[i].name);
        scanf("%d",&stu[i].grade);
    }
    switch(c){
        case 1:
            sort(stu.begin(),stu.end(),cmp1);

            break;
        case 2:
            sort(stu.begin(),stu.end(),cmp2);
            break;
        case 3:
            sort(stu.begin(),stu.end(),cmp3);
            break;
    };
    for(i=0;i<num;i++){
        cout<<stu[i].id<<" "<<stu[i].name;
        printf(" %d",stu[i].grade);
    }
}
