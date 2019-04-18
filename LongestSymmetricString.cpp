//2019.4.18
//暴力破解方法
#include<iostream>
#include<string>
using namespace std;
int main(){
	int res=1,j,k,tmp;
	string str;
	getline(cin,str);
	int len = str.length();
	//for(int i=1;i<(len-res/2);i++){
	for(int i=0;i<len-1;i++){
		//ÆæÊý¶Ô³Æ 
		j=i-1;k=i+1;
		tmp = 1;
		while(j>=0&&k<len&&str[j]==str[k]){
			j--;k++;
			tmp+=2;
		}
		if(tmp>res) res = tmp;
		//Å¼Êý¶Ô³Æ 
		tmp = 0;
		j=i;k=i+1;
		while(j>=0&&k<len&&str[j]==str[k]){
			j--;k++;
			tmp+=2;
		}
		if(tmp>res) res = tmp;
	}
	printf("%d",res);
} 
