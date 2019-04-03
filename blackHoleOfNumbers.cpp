//2019.4.3
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	int n,low,high;
	scanf("%d",&n);
	char num[5];
	do{
		sprintf(num,"%04d",n);
		sort(num,num+4);
		sscanf(num,"%d",&low);
		sort(num,num+4,cmp);
		sscanf(num,"%d",&high);
		n = high - low;
		printf("%04d - %04d = %04d\n",high,low,n);
	}while(!(n==0||n==6174));
	return 0;
} 
