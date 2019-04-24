//2019.4.24
#include<stdio.h>
#include<algorithm>
#include<vector> 
using namespace std;
int main(){
	int n,count=0,max=0;
	scanf("%d",&n);
	vector<int> ori(n),pro(n);
	vector<int> res;
	for(int i=0;i<n;i++){
		scanf("%d",&ori[i]);
	}
	pro = ori;
	sort(pro.begin(),pro.end());
	for(int i=0;i<n;i++){
		if(pro[i]==ori[i]&&ori[i]>max){
			count++;
			res.push_back(pro[i]);
		}
		if(ori[i]>max) max = ori[i];
	}
	if(count==0){
		printf("0\n\n");
		//测试点2 如果没有pivot  则应该输出一行空行  否则提示格式错误 
		return 0;
	}
	printf("%d\n%d",count,res[0]);
	for(vector<int>::iterator it=res.begin()+1;it!=res.end();it++)
		printf(" %d",*it);
} 
