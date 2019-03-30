//2019.3.28 start time:10:17
//账单排序加分时计费
#include<iostream>
#include<string>
#include<algorithm>
#include<iomanip>
using namespace std;
struct Time{
    string name;
    string time;
    string label;
}rec[1000];
bool cmp(Time t1,Time t2){
    if(t1.name!=t2.name) return t1.name<t2.name;
    else return t1.time<t2.time;
}
int main(){
    int price[24];
    int i,j,num;
    for(i=0;i<24;i++)
        cin>>price[i];
    cin>>num;
    i=0;
    string tmp;
    cin>>rec[0].name>>tmp>>rec[0].label;
    char month[3]={0};
    month[0] = tmp[0];
    month[1] = tmp[1];
    rec[0].time=tmp.substr(3);

    for(i=1;i<num;i++){
        cin>>rec[i].name>>tmp>>rec[i].label;
        rec[i].time=tmp.substr(3);
    }
    sort(rec,rec+num,cmp);
    i=0;
    int amount=0;
    int d1,d2,h1,h2,m1,m2,totalTime,current;
    char transit[10];
    while(i<num-1){
        if(rec[i].name == rec[i+1].name){//名字相同，用户未改变
            if(rec[i].label == "on-line"&&rec[i+1].label=="off-line"){
                //配对成功 计算费用
                if(rec[i].time==rec[i+1].time) {i++;continue;}
                if(amount==0){
                    cout<<rec[i].name<<" "<<month<<endl;
                }
                rec[i].time.copy(transit,10);
                sscanf(transit,"%d:%d:%d",&d1,&h1,&m1);
                rec[i+1].time.copy(transit,10);
                sscanf(transit,"%d:%d:%d:",&d2,&h2,&m2);
                current = 0;
                totalTime=0;
                //模拟时间进行计费
                while(d1!=d2||h1!=h2||m1!=m2){
                    current+=price[h1];
                    totalTime++;
                    m1++;
                    if(m1==60){
                        h1++;
                        m1=0;
                        if(h1==24){
                            h1=0;
                            d1++;
                        }
                    }
                }
                cout<<rec[i].time<<" "<<rec[i+1].time<<" "<<totalTime<<" $"<<setiosflags(ios::fixed)<<setprecision(2)<<current/100.0<<endl;
                amount+=current;
            }
        }
        else{
            // 用户改变
            if(amount>0){//如果上一个用户产生有效账单，则输出总额
                cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<amount/100.0<<endl;
            }
            amount=0;
        }
        i++;
    }
    //如果最后一个用户产生有效费用，则输出相应信息
    if(amount>0)    cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<amount/100.0<<endl;
}
