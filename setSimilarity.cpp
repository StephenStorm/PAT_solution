//2019.4.11
//本题利用set的特性实现
//将两个查询的set合并后为all，则nt = all.size(),nc = set1.size+set2.size-nt;
//由此求得相似度 
#include<stdio.h>
#include<set>
#include<vector>
using namespace std;
int main(){
	int n,m,k,i,j,tmp;
	scanf("%d",&n);
	vector<set<int> > sets(n);
	for(i=0;i<n;i++){
		scanf("%d",&m);
		for(j=0;j<m;j++){
			scanf("%d",&tmp);
			sets[i].insert(tmp);
		}
	} 
	scanf("%d",&k);
	int fir,sec,nc,nt;
	set<int> all;
	for(i=0;i<k;i++){
		scanf("%d %d",&fir,&sec);
		fir--;sec--;
		all.clear();
		all.insert(sets[fir].begin(),sets[fir].end());
		all.insert(sets[sec].begin(),sets[sec].end());
		nt = all.size();
		nc = sets[fir].size()+sets[sec].size()-nt;
		printf("%.1f%%\n",(1.0*nc/nt)*100);
	}
} 
