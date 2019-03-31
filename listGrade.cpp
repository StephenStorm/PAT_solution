//2019.3.31
#include<vector>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct grade{
    char name[11];
    char id[11];
    int score;
};
bool cmp(grade g1,grade g2){
    return g1.score>g2.score;
}
int main(){
    int num;
    scanf("%d",&num);
    vector<grade> grades(num);
    int i;
    for(i=0;i<num;i++){
        scanf("%s %s %d",grades[i].name,grades[i].id,&grades[i].score);
    }
    int low,high;
    scanf("%d %d",&low,&high);
    sort(grades.begin(),grades.end(),cmp);
    bool isfind= false;
    for(i=0;i<num;i++){
        if(grades[i].score>=low&&grades[i].score<=high){
            printf("%s %s\n",grades[i].name,grades[i].id);
            isfind = true;
        }
    }
    if(!isfind) printf("NONE\n");
    return 0;
}
