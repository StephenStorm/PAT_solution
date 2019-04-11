//2019.4.11
#include<stdio.h>
#include<map>
int matrix[801][601];
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif 
	int m,n;
	scanf("%d%d",&m,&n);
	int i,j,ter=m*n,tmp;
	map<int,int> color;
	for(i=0;i<ter;i++){
		scanf("%d",&tmp);
		color[tmp]++;
	}
	int mid = ter / 2;
	for(map<int,int>::iterator it = color.begin();it!=color.end();it++){
		if(it->second>mid) printf("%d",it->first);
	}
} 
