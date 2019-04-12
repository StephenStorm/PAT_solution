//2019.4.12
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main(){
	int n;
	long long p;
	scanf("%d%lld",&n,&p);
	vector<int> num(n);
	int i,j;
	for(i=0;i<n;i++)
		scanf("%d",&num[i]);
	sort(num.begin(),num.end());
	int dis = 0;
	for(i=0;n-i>dis;i++){
		dis = max((int)(upper_bound(num.begin(),num.end(),num[i]*p)-(num.begin()+i)),dis);
	}
	cout<<dis;
} 
