//2019.5.10
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string transform(string str,int n){
	string res="0.";
	int a = str.find_first_of('.'),b=0;
	a=a>0?a:str.size();//?????? 
	while(b<str.length()&&(str[b]==48|| str[b]=='.') )b++;
	//??????????
	if(b==str.size()) {
		for(int i=0;i<n;i++)
			res.append(1,'0');
		res+="*10^0";
		return res;
	}
	int power=a-b,count=0;
	if(power<0) power++;
	for(int i=b;count<n&&i<str.length();i++){
		if(str[b]!='.') res.append(1,str[i]);
		count++;
	}
	while(count<n){
		res.append(1,'0');
		count++;
	}
	res+="*10^"+to_string(power);
	return res;
}
int main(){
	int i,n=3;
	string str1,str2,t1,t2;
//	cin>>n>>str1>>str2;
while(1){
	cin>>str1>>str2;
	t1=transform(str1,n);
	t2=transform(str2,n);
	if(t1==t2){
		cout<<"YES "<<t1; 
	} 
	else cout<<"NO "<<t1<<" "<<t2<<endl;
}
	return 0;
}
