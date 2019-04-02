//2019.4.2
//find coins   hashtable方法
#include<stdio.h>
using namespace std;
int num[1001]={0};//保存面额等于数组下标的钱币数量 
int main(){
	int n,m;
	scanf("%d %d",&n,&m);
	int i,value;
	for(i=0;i<n;i++){
		scanf("%d",&value);
		num[value]++;
	}
	for(i=1;i<(m<501?m:501);i++){
		if(num[i]>0&&num[m-i]>0){
			if((i+i)!= m ||num[i]>1) {
				printf("%d %d",i,m-i);
				return 0;
			}
		}
	}
	printf("No Solution");
} 
