//2019.4.12
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string str1,str2;
	cin>>str1>>str2;
	int i=0,j=0;
	char ch;
	vector<char> res;
	while(i<str1.length()||j<str2.length()){
		if(j<str2.length()&&str1[i] == str2[j]){
			i++;
			j++;
		}
		else{
			ch = str1[i];
			if(ch>='a'&&ch<='z') ch-=32;
			if(find(res.begin(),res.end(),ch) == res.end()){
				res.push_back(ch);
			}
			i++;
		}
	}
	/*
	while(i<str1.length()){
		ch = str1[i];
		if(ch>='a'&&ch<='z') ch-=32;
		
	}
	*/
	for(vector<char>::iterator it = res.begin();it!=res.end();it++){
		printf("%c",*it);
	}
	
} 
