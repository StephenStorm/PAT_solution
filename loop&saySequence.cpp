//2019.4.15
#include<iostream>
#include<string>
using namespace std;
int main(){
	//map<char,int> count;
	int n,j,count;
	char ch;
	string str; 
	cin>>str>>n;
	for(int i=1;i<n;i++){
		j=0;
		count = 0;
		string tt;
		while(j<str.length()){
			ch = str[j];
			while(j<str.length()&&str[j]==ch){
				count++;
				j++;
			}
			tt+=ch+to_string(count);
			count = 0;
		}
		str = tt; 
	}
	cout<<str;
	return 0;
}
