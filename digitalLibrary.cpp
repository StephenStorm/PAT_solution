//2019.4.16
#include<map>
#include<set>
#include<string>
#include<iostream>
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,m,i,id;
	scanf("%d",&n);
	map<string,set<int> > maps[5];//title,auther,key,publisher;
	char ch,keyWord[11],year[5];
	string tit,auth,pub;
	for(i=0;i<n;i++){
		scanf("%d",&id);
		getchar();
		getline(cin,tit);
		getline(cin,auth);
		maps[0][tit].insert(id);
		maps[1][auth].insert(id);
		do{
			scanf("%s",keyWord);
			maps[2][keyWord].insert(id);
			ch = getchar();
		}while(ch != '\n'); 
		getline(cin,pub);
		scanf("%s",year);
		getchar();
		maps[3][pub].insert(id);
		maps[4][year].insert(id);
	}
	scanf("%d",&m);
	getchar();
	int num;
	for(i=0;i<m;i++){
		getline(cin,tit);
		num = (int)(tit[0]-48);
		cout<<tit<<endl;
		tit=tit.substr(3); 
		if(maps[num-1][tit].size() == 0) printf("Not Found\n");
		else{
			for(set<int>::iterator it = maps[num-1][tit].begin();it!=maps[num-1][tit].end();it++){
				printf("%07d\n",*it);
			}
		}
	}
} 
