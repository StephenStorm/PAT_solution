//20191.4.10
#include<stdio.h>
#include<vector>
#include<set>
#include<string>
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	scanf("%d%d",&n,&k);
	vector<set<string> > grade(k+1);
	int i,j,num,index;
	char name[4];
	for(i=0;i<n;i++){
		scanf("%s %d",name,&num);
		for(j=0;j<num;j++){
			scanf("%d",&index);
			grade[index].insert(name);
		}
	}
	for(i=1;i<=k;i++){
		printf("%d %d\n",i,grade[i].size());
		for(set<string>::iterator it = grade[i].begin();it!=grade[i].end();it++){
			cout<<*it;
		}
	}
}

