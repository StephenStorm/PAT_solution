//2019.5.4
//����1-5���Ե���� �������룬�����������������ֵ+1 
#include<stdio.h>
#include<set>
using namespace std;
int main(){
	int n,i,tmp;
	set<int> flag;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		if(tmp>0) flag.insert(tmp);
	}
	i=1;
	for(set<int>::iterator it = flag.begin();it!=flag.end();it++){
		if(*it!=i) break; 
		i++;
	} 
	printf("%d",i);
	return 0;
} 
