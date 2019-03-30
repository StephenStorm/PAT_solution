//2019.3.30 start time: 19:45 ACtime 20:15
//当数据量很大时 cin 函数的使用会大大降低程序效率
#include<algorithm>
#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
struct wealth{
    char name[9];
    int age;
    int netWealth;
};
bool cmp(wealth w1,wealth w2){
    if(w1.netWealth!=w2.netWealth){
        return w1.netWealth>w2.netWealth;
    }
    else{
        if(w1.age != w2.age)
            return w1.age<w2.age;
        else return strcmp(w1.name,w2.name)<0?true:false;
    }

}
int main(){
    char tmp[9];
    int num1,num2;
    cin>>num1>>num2;
    vector<wealth> wea(num1);
    int i;
    for(i=0;i<num1;i++){
        //scanf("%s",tmp);
       // wea[i].name = tmp;
        //tmp=0;
        //cin>>wea[i].name;
        scanf("%s %d %d",wea[i].name,&wea[i].age,&wea[i].netWealth);
    }
    sort(wea.begin(),wea.end(),cmp);
    int low,high,amount=0,limit,j;
    for(j=0;j<num2;j++){
        scanf("%d %d %d",&limit,&low,&high);
        printf("Case #%d:\n",j+1);
        i=0;
        amount = 0;
        while(i<num1&&amount<limit){
            if(wea[i].age>=low&&wea[i].age<=high){
                //cout<<wea[i].name;
                printf("%s %d %d\n",wea[i].name,wea[i].age,wea[i].netWealth);
                amount++;
            }
            i++;
        }
        if(amount==0) printf("None\n");
    }
}


