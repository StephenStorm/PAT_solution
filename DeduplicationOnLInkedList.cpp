//2019.4.17
#include<stdio.h>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>
using namespace std;
struct node{
	int key,next;
}list[100001];
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int start,n,addr,i;
	scanf("%d%d",&start,&n);
	for(i=0;i<n;i++){
		scanf("%d",&addr);
		scanf("%d%d",&list[addr].key,&list[addr].next);
	}
	set<int> test;
	pair<set<int>::iterator,bool> flag;
	vector<int> linked,repeated;
	while(start!=-1){
		flag = test.insert(abs(list[start].key));
		if(!flag.second){
			repeated.push_back(start);
		}
		else{
			linked.push_back(start);
		}
		start = list[start].next;
	}
	if(linked.size()>0){
		for(i=0;i<linked.size()-1;i++){
			printf("%05d %d %05d\n",linked[i],list[linked[i]].key,linked[i+1]);
		}
		printf("%05d %d -1\n",linked[i],list[linked[i]].key);
	}
	if(repeated.size()>0){
		for(i=0;i<repeated.size()-1;i++){
			printf("%05d %d %05d\n",repeated[i],list[repeated[i]].key,repeated[i+1]);
		}
		printf("%05d %d -1\n",repeated[i],list[repeated[i]].key);
	}
}
