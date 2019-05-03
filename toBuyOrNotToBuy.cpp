//2019.5.3
#include<stdio.h>
#include<unordered_map>
#include<cstring>
using namespace std;
int main(){
	char t1[1001],t2[1001],ch;
	scanf("%s %s",t1,t2);
	int len1=strlen(t1),len2=strlen(t2);
	unordered_map<char,int> maps;
	for(int i=0;i<len1;i++){
		ch = t1[i];
		maps[ch]++;
	} 
	bool flag = true;
	for(int i=0;i<len2;i++){
		if(maps[t2[i]]<=0)
			flag = false;
		maps[t2[i]]--;
	}
	int count = 0;
	if(flag){
		for(unordered_map<char,int>::iterator it = maps.begin();it!=maps.end();it++)
			count+=it->second;
		printf("Yes %d",count);
	}
	else{
		for(unordered_map<char,int>::iterator it = maps.begin();it!=maps.end();it++)
			if(it->second<0) count-=it->second;
		printf("No %d",count);
	}
}
