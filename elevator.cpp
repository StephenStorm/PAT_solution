//2019.4.8
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	int num,i,j;
	scanf("%d",&num);
	vector<int> vec(num+1);
	vec[0] = 0;
	for(i=1;i<=num;i++)
		scanf("%d",&vec[i]);
	int tmp,sum = num*5;
	for(i=1;i<=num;i++){
		tmp = vec[i]-vec[i-1];
		if(tmp>0)
			sum += tmp*6;
		else
			sum += -tmp*4;
	}
	printf("%d",sum); 
}
