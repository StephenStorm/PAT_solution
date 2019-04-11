//2019.4.11
#include<iostream>
#include<string>
#include<map>
using namespace std;
bool islegal(char ch){
	if(ch>='0'&&ch<='9') return true;
	if(ch>='a'&&ch<='z') return true;
	if(ch>='A'&&ch<='Z') return true;
	return false;
}
int main(){
	string str;
	getline(cin,str);
	map<string,int> count;
	int i=0,len = str.length();
	while(i<len){
		string word;
		while(i<len&&islegal(str[i])){
			if(str[i]>='A'&&str[i]<='Z') str[i]+=32;
			word+=str[i];
			i++;
		}
		if(word !="")
			count[word]++;
		while(i<len&&!islegal(str[i])){
			i++;
		}
	}
	int max = 0;
	string res;
	for(map<string,int>::iterator it=count.begin();it!=count.end();it++){
		if(it->second>max){
			max = it->second;
			res = it->first;
		}
	}
	cout<<res<<" "<<max;
} 
