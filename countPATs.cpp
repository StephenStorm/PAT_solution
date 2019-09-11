//2019.9.8 
//countPAts
// https://pintia.cn/problem-sets/994805342720868352/problems/994805373582557184
#include<iostream>
#include<string>
using namespace std;
int main(){
	string str;
	cin>>str;
	int len = str.length();
	int i,ct=0,cp=0;
	for(i=0;i<len;i++){
		if(str[i]=='T') ct++;
	}
	int num=0;
	for(i=0;i<len-1;i++){
		if(str[i] == 'P') cp++;
		if(str[i] == 'T') ct--;
		if(str[i] == 'A') num = (num+(cp*ct)%1000000007)%1000000007;
	}
	printf("%d",num);
	return 0;
}	
