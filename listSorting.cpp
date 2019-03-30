//2019.3.30 start time: 17:45 ACtime 18:14
//不同关键字排序
//本程序收获：
//最大的收获在于发现了 cin和cout函数在输入大量的数据时非常耗时，效率不如scanf和printf；
//同时发现是scanf函数不能用%s  控制输入string类
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
    //以id为关键字
    return r1.id<r2.id;
}
bool cmp2(record r1,record r2){
    //name为主关键字，id为副关键字
    return r1.name==r2.name?r1.id<r2.id:r1.name<r2.name;
}
bool cmp3(record r1,record r2){//类比
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
