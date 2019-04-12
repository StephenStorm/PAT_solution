//2019.4.12
#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	int n,b;
	scanf("%d%d",&n,&b);
	if(n==0){
		printf("Yes\n0");
		return 0 ;
	}
	vector<int> dig;
	while(n!=0){
		dig.push_back(n%b);
		n/=b;
	}
	int i=0,j = dig.size()-1;
	bool flag = true;
	while(i<=j){
		if(dig[i] == dig[j]){
			i++;
			j--;
		}
		else{
			flag = false;
			break;
		}
	}
	if(flag)
		printf("Yes\n");
	else
		printf("No\n");
	printf("%d",dig.back());
	for(vector<int>::reverse_iterator it = dig.rbegin()+1;it!=dig.rend();it++){
		printf(" %d",*it);
	}
} 
