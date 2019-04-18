//2019.4.17
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	int i,j,n,m,t1,t2,sum=0,tmp;
	scanf("%d",&n);
	vector<int> vec(n+1);
	//vec[i]存储i出口到1出口的距离 
	vec[1] = 0;
	for(i=2;i<=n;i++){
		scanf("%d",&tmp);
		vec[i]=vec[i-1]+tmp;
	}
	scanf("%d",&tmp);
	sum = tmp+vec[n];
	scanf("%d",&m);
	for(i=0;i<m;i++){
		scanf("%d%d",&t1,&t2);
		tmp = abs(vec[t1]-vec[t2]);
		printf("%d\n",tmp<(sum-tmp)?tmp:sum-tmp);
	}
}
