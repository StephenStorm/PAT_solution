//2019.5.26
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
struct node{
	int id;
	vector<int> child;
};
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,m,i,j,tid,k,tmp;
	scanf("%d %d",&n,&m);
	if(n==1) {printf("1");return 0;} 
	vector<node> nodes(n+1);
	for(i=0;i<m;i++){
		scanf("%d %d",&tid,&k);
		for(j=0;j<k;j++){
			scanf("%d",&tmp);
			nodes[tid].child.push_back(tmp); 
		}
	}
	printf("0");
	queue<int> que;
	
	for(i=0;i<nodes[1].child.size();i++){
		que.push(nodes[1].child[i]);
	}
	que.push(0);
	int count=0;
	while(!que.empty()){
		tmp = que.front();
		que.pop();
		if(tmp==0){
			printf(" %d",count);
			count = 0;
			if(!que.empty())  que.push(0);
			continue;
		} 
		if(nodes[tmp].child.empty()) count++;
		//¸该节点为叶节点
		else{
			for(i=0;i<nodes[tmp].child.size();i++){
				que.push(nodes[tmp].child[i]);
			}
		}
	}
	return 0;
}
