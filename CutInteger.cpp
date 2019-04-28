//2019.4.28
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	int n,i,len,j,t1,t2,num;
	scanf("%d",&n);
	string str;
	long long product;
	string tmp1,tmp2;
	for(i=0;i<n;i++){
		cin>>str;
		len = str.length()/2;
		tmp1=str.substr(0,len);
		tmp2=str.substr(len);
		sscanf(str.c_str(),"%d",&num);
		sscanf(tmp1.c_str(),"%d",&t1);
		sscanf(tmp2.c_str(),"%d",&t2);
		product = t1*t2;
		if(product==0){printf("No\n");continue;}
		if(num>=product&&num%product==0)printf("Yes\n");
		else printf("No\n");
	}
} 
