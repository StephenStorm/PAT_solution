//2019.4.5
//这道题目采用这种前后组合字符串进行比较的方式 我还是比较有成就感的
//毕竟想了大半天突然发现  采用这种比较方式既简单 又易于理解 
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct num{
	char dig[9];
};
bool cmp(num n1,num n2){
	char tmp1[17],tmp2[17];
	strcpy(tmp1,n1.dig);
	strcat(tmp1,n2.dig);
	strcpy(tmp2,n2.dig);
	strcat(tmp2,n1.dig);
	return strcmp(tmp1,tmp2)<0?true:false;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	int i = 0;
	vector<num> vec(n);
	for(i=0;i<n;i++){
		scanf("%s",&vec[i]);
	}
	sort(vec.begin(),vec.end(),cmp);
	bool flag = false;
	int j=0;
	while(j<n&&!flag){
		i=0;
		while(i<strlen(vec[j].dig)&&vec[j].dig[i] == 48)
			i++;
		while(i<strlen(vec[j].dig)) {
			printf("%c",vec[j].dig[i]);
			flag = true;
			i++;
		}
		j++;
	}
	if(j==n){//全是0的情况  对应与测试点2  坑死 
		printf("0");
		return 0;
	}
	for(i=j;i<n;i++){
		printf("%s",vec[i].dig);
	}
	return 0;
} 
