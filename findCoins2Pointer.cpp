//2019.4.2
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int n,k;
	scanf("%d %d",&n,&k);
	vector<int> coins(n);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%d",&coins[i]);
	}
	//进行排序后前后进行匹配 
	sort(coins.begin(),coins.end());
	i=0;
	int start=coins.size()-1;
	for(i=0;i<n;i++){
		for(j=start;j>i;j--){
			if(coins[i]+coins[j]>k){
				//如果现在的j使得两数之和超过课，则i+1个数的开始值应当<=j 
				start = j;
				continue;
			}
			if(coins[i]+coins[j]<k) break;
			printf("%d %d",coins[i],coins[j]);
			return 0;
		}
	}
	printf("No Solution");
	return 0;
}
