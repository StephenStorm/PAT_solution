//2019.4.1
//sort
#include<algorithm>
#include<stdio.h>
#include<map>
#include<vector>
#include<string.h>
#include<string>
using namespace std;
struct record{
    char plate[8];
    int time;
    int status;//1 present in /-1 present out
};
bool cmpId(record r1,record r2){
    return strcmp(r1.plate,r2.plate)==0?(r1.time<r2.time):(strcmp(r1.plate,r2.plate)<0);
}
bool cmpTime(record r1,record r2){
    return r1.time<r2.time;
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE

    int num1,num2,i,j,h,m,s;
    scanf("%d%d",&num1,&num2);
    vector<record> vec(num1);
    char state[4];
    for(i=0;i<num1;i++){
        scanf("%s %d:%d:%d %s",vec[i].plate,&h,&m,&s,state);
        vec[i].time = h*3600+m*60+s;
        vec[i].status = (state[0]=='i'?1:-1);
    }
    sort(vec.begin(),vec.end(),cmpId);
    //删除无效元素 并记录时长
    vector<record> valid(num1);
    map<string,int> timing;
    i=0;
    int amount = 0,maxtime=-1,tmpTime;
    while(i<num1-1){
        if(strcmp(vec[i].plate,vec[i+1].plate)==0 && vec[i].status==1 &&vec[i+1].status == -1){
            valid[amount++]=vec[i];
            valid[amount++]=vec[i+1];
            tmpTime = vec[i+1].time-vec[i].time;

            if(timing.count(vec[i].plate)==0)
                timing[vec[i].plate] = 0;
            timing[vec[i].plate]+=tmpTime;
            maxtime = max(maxtime,timing[vec[i].plate]);
            i++;
        }
        i++;
    }
    sort(valid.begin(),valid.begin()+amount,cmpTime);
    int count1=0;
    j=0;
    for(i=0;i<num2;i++){
        scanf("%d:%d:%d",&h,&m,&s);
        tmpTime=h*3600+m*60+s;
        while(j<amount&&valid[j].time<=tmpTime){
            count1+=valid[j].status;
            j++;
        }
        printf("%d\n",count1);
    }
    for(map<string,int>::iterator it=timing.begin();it!=timing.end();it++){
        if(it->second==maxtime) printf("%s ",it->first.c_str());
    }
    printf("%02d:%02d:%02d",maxtime/3600,maxtime%3600/60,maxtime%60);
}
