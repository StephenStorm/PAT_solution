//2019.3.28 start time:10:17
//�˵�����ӷ�ʱ�Ʒ�
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
        if(rec[i].name == rec[i+1].name){//������ͬ���û�δ�ı�
            if(rec[i].label == "on-line"&&rec[i+1].label=="off-line"){
                //��Գɹ� �������
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
                //ģ��ʱ����мƷ�
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
            // �û��ı�
            if(amount>0){//�����һ���û�������Ч�˵���������ܶ�
                cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<amount/100.0<<endl;
            }
            amount=0;
        }
        i++;
    }
    //������һ���û�������Ч���ã��������Ӧ��Ϣ
    if(amount>0)    cout<<"Total amount: $"<<setiosflags(ios::fixed)<<setprecision(2)<<amount/100.0<<endl;
}
