//2019.4.17
#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int address,key,next;
	bool flag=false;
}list[100001]; 
bool cmp(node n1,node n2){
	if(!n1.flag||!n2.flag)
		return n1.flag>n2.flag;
	else{
		return n1.key<n2.key;
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,start,addr,next,count = 0;
	scanf("%d%d",&n,&start);
	if(start == -1) {printf("0 -1");return 0;}
	//最后一个测试点，链表的长度为0，可以根据开始节点直接判断 
	for(int i=0;i<n;i++){
		scanf("%d",&addr);
		scanf("%d %d",&list[addr].key,&list[addr].next);
		list[addr].address = addr;
	}
	while(start!=-1){
		list[start].flag = true;
		count++;
		start = list[start].next;
	}
	sort(list,list+100001,cmp);
	printf("%d %05d\n",count,list[0].address);
	for(int i=0;i<count-1;i++){
		printf("%05d %d %05d\n",list[i].address,list[i].key,list[i+1].address);
	}
	printf("%05d %d -1",list[count-1].address,list[count-1].key);
	return 0;
}
