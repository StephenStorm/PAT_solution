//2019.4.11
#include<stdio.h>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;
char** name;
//char name[40001][5];
bool cmp(int a,int b){
	if(strcmp(name[a],name[b])<0) return true;
	return false;
}
//由于要排序的数组存储的是name数组的下标，所以比较的输入为int型。 
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,k;
	scanf("%d%d",&n,&k);
	vector<vector<int> > course(k+1);
	//int型二维数组[i][j]，存储课程号为i的学生姓名下标 
	name = new char*[n];
	//可以理解为一维字符串数组，存储所有学生的名字 
	int i,j,num,couNum;
	for(i=0;i<n;i++){
		name[i] = new char[5];
	}
	for(i=0;i<n;i++){
		scanf("%s %d",name[i],&num);
		for(j=0;j<num;j++){
			scanf("%d",&couNum);
			course[couNum].push_back(i);
		}
	}
	for(i=1;i<=k;i++){
		sort(course[i].begin(),course[i].end(),cmp);
		printf("%d %d\n",i,course[i].size());
		for(vector<int>::iterator it=course[i].begin();it!=course[i].end();it++){
			printf("%s\n",name[*it]);
		} 
	}
	//释放动态申请的空间 
	for(i=0;i<n;i++){
		delete[] name[i];
	} 
	delete[] name;
}
