//2019.4.10
//�������map<string,set<int>>���ݽṹ�洢ѧ��ѡ����Ϣ
//keyΪѧ��������setΪ�γ��������� 
#include<stdio.h>
#include<set>
#include<string>
#include<map>
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	scanf("%d%d",&n,&k);
	map<string,set<int> > grade;
	int i,j,index,num;
	char name[4];
	for(i=0;i<k;i++){
		scanf("%d%d",&index,&num);
		for(j=0;j<num;j++){
			scanf("%s",name);
			grade[name].insert(index);
		}
	}
	for(i=0;i<n;i++){
		scanf("%s",name);
		printf("%s",name);
		printf(" %d",grade[name].size());
		for(set<int>::iterator it = grade[name].begin();it!=grade[name].end();it++){
			printf(" %d",*it);
		}
		printf("\n");
	}	
} 

