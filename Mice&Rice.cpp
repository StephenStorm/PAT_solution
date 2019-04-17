#include<stdio.h>
#include<vector>
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int np,ng;
	scanf("%d%d",&np,&ng);
	vector<int> weight(np);
	vector<int> vec[2];
	vector<int> rank(np);
	vec[0].resize(np);
	vec[1].resize(np);
	int i,j,s;
	for(i=0;i<np;i++)
		scanf("%d",&weight[i]);
	for(i=0;i<np;i++)
		scanf("%d",&vec[0][i]);
	int current=1,last = 0,tmax,tmp,gnum,size = np;
	while(size!=1){
		s=0;
		gnum = size/ng+(size%ng==0?0:1); 
		for(i=0;i<gnum-1;i++){
			j=ng*i;
			tmax = vec[last][j];
			for(j;j<ng*i+ng;j++){
				rank[vec[last][j]] = gnum+1; 
				if(weight[tmax]<weight[vec[last][j]]) tmax = vec[last][j];
			}
			vec[current][s++]=tmax;
		}
		j=i*ng;
		tmax = vec[last][j];
		while(j<size){
			rank[vec[last][j]] = gnum+1;
			if(weight[tmax]<weight[vec[last][j]]) tmax = vec[last][j];
			j++;
		}
		vec[current][s++] = tmax;
		size = gnum;
		last = 1-last;
		current = 1-current;
	}
	rank[vec[last][0]] = 1;
	printf("%d",rank[0]);
	for(i=1;i<np;i++) printf(" %d",rank[i]);
} 
