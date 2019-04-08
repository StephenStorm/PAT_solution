//2019.4.8
#include<stdio.h>
int first[200005];
using namespace std;
int main(){
	int n1,n2,i,j;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
		scanf("%d",&first[i]);
	scanf("%d",&n2);
	int mid = (n1+n2-1)/2;
	int result,tmp;
	i=0;
	j=0;
	scanf("%d",&tmp);
	while(i<n1&&j<n2){
		if(first[i]<tmp){
			result = first[i];
			i++;
		}
		else{
			result = tmp;
			scanf("%d",&tmp);
			j++;
		} 
		if(i+j-1 == mid){//(i-1) + (j-1) +2 - 1   两个下标之和加上2是总个数，减去1是下标 
			printf("%d",result);
			return 0;
		}
	}
	if(i==n1){
		while(n1+j<mid){
			scanf("%d",&tmp);
			j++;
		}
		printf("%d",tmp);
	}
	else{
		printf("%d",first[mid-n2]);
	}
	return 0;
}
