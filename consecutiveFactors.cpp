//2019.8.9
// https://pintia.cn/problem-sets/994805342720868352/problems/994805370650738688
//最长连续因子 
#include<cmath>
#include<iostream>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	int first = 0,i,j;
	int maxn = sqrt(n)+1,len = 0;
	for(i=2;i<=maxn;i++){
		int temp= 1;
		for(j=i;j<maxn;j++){
			temp*=j;
			if(n%temp != 0) break; 
		}
		if(j-i>len){
			len=j-i;
			first = i;
		}
	}
	if(first==0){
		cout<<1<<endl<<n;
	}
	else{
		cout<<len<<endl;
		for(i=0;i<len;i++){
			cout<<first+i;
			if(i!=len-1) cout<<"*";
		}
	}
	return 0;
}
