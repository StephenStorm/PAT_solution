//2019.4.17
#include<stdio.h>
#include<set>
#include<utility>
using namespace std;
int list[100000];
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int add1,add2,n,t1,t2;
	char ch;
	scanf("%d %d %d",&add1,&add2,&n);
	if(add1==-1||add2==-1){
		printf("-1");
		return 0;
	}
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&t1,&ch,&t2);
		list[t1] = t2;
	}
	set<int> pos;
	t1=add1;
	while(t1!=-1){
		pos.insert(t1);
		t1=list[t1];
	}
	pair<set<int>::iterator,bool> flag;
	t2=add2;
	do{
		flag = pos.insert(t2);
		t1=t2;
		t2=list[t2];
	}while(t2!=-1&&flag.second);
	if(!flag.second)
		printf("%05d",t1);
	else
		printf("-1");
	return 0;
} 
