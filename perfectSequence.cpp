//2019.4.12
#include<stdio.h>
#include<algorithm>
#include<vector>
#define ll long long 
using namespace std;
int main(){
	int n;
	ll p;
	scanf("%d%d",&n,&p);
	vector<int> num(n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	sort(num.begin(),num.end());
	int max=0;
	for(i=0;n-i>max;i++){
		j=i+max;
		while(j<n&&num[j]<=num[i]*p){
			//�˴�ע�⣬�������ĳ˻����ܳ���int�ı�ʾ��Χ��������ll���� 
			j++;
		} 
		if(j-i>max)	
			max = j-i;
	}
	printf("%d",max);
} 
