//2019.4.16
#include<stdio.h>
#include<set>
using namespace std;
int main(){
	int n,tmp,sum;
	set<int> id;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&tmp);
		sum = 0;
		while(tmp!=0){
			sum+=tmp%10;
			tmp/=10;
		}
		id.insert(sum);
	}
	printf("%d\n",id.size());
	for(set<int>::iterator it = id.begin();it!=id.end();it++){
		if(it!=id.begin()) printf(" ");
		printf("%d",*it);
	}
}
