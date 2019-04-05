//2019.4.5
//Ì°ÐÄ
#include<algorithm>
#include<vector>
#include<stdio.h>
using namespace std;
int main(){
	int num1,num2;
	scanf("%d",&num1);
	vector<int> cou(num1);
	int i;
	for(i=0;i<num1;i++){
		scanf("%d",&cou[i]);
	}
	scanf("%d",&num2);
	vector<int> pro(num2);
	for(i=0;i<num2;i++){
		scanf("%d",&pro[i]);
	}
	sort(cou.begin(),cou.end());
	sort(pro.begin(),pro.end());
	i = 0;
	long sum = 0;
	int min = num1>num2?num2:num1;
	while(i<min&&cou[i]<0&&pro[i]<0){
		sum+=cou[i]*pro[i];
		i++;
	}
	i=1;
	while(i<=min&&cou[num1-i]>0&&pro[num2-i]>0){
		sum+=cou[num1-i]*pro[num2-i];
		i++;
	}
	printf("%d",sum);
} 
