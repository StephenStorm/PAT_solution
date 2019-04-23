//2019.4.23
#include<iostream>
#include<set>
#include<string>
#include<vector> 
#include<utility>
using namespace std;
int main(){
	int m,n,s,i,j;
	scanf("%d%d%d",&m,&n,&s);
	if(s>m) {
		printf("Keep going...\n");
		return 0;
	}
	vector<string> str(m+1);
	for(i=1;i<=m;i++){
		cin>>str[i]; 
	}
	set<string> sets;
	pair<set<string>::iterator,bool> flag;
	i=s;
	while(i<=m){
		do{
			flag=sets.insert(str[i]);
			i++;
		}while(i<=m&&flag.second==false);
		cout<<str[i-1]<<endl;
		i=i+n-1;
		
	}
	return 0;
} 
