//2019.5.12
//利用map简化问题计算 
#include<iostream>
#include<map>
#include<cstring>
#include<vector>
using namespace std;
char str[1001];
int main(){
	int k,i=0,j;
	scanf("%d",&k);
	scanf("%s",str);
	map<char,int> count;
	vector<char> res;
	int len = strlen(str),tmp;
	while(i<len){
		j=i;
		while(j<len&&str[j]==str[i]) j++;
		tmp=j-i;
		if(tmp%k==0){
			if(count[str[i]]==0)  {
				count[str[i]]=1;
				res.push_back(str[i]); 
			}
		} 
		else
			count[str[i]]=-1;
		i=j;
	} 
	for(i=0;i<res.size();i++)
		if(count[res[i]]==1) 
			printf("%c",res[i]);
	printf("\n"); 
	i=0;
	while(i<len){
		printf("%c",str[i]);
		if(count[str[i]]==1){
			i+=k;
		}
		else i++;
	}
	printf("%c",0);
	return 0;
} 
