//2019.6.9
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
struct person{
	char id[9];
	int Vgrade;
	int Tgrade;
	int totalgrade;
	int level;//1  sage   2	nobleman  3	foolman   4  smallman 
};
bool cmp(person p1,person p2){
	if(p1.level!=p2.level) return p1.level<p2.level;
	if(p1.totalgrade!=p2.totalgrade) return p1.totalgrade>p2.totalgrade;
	if(p1.Vgrade!=p2.Vgrade) return p1.Vgrade>p2.Vgrade;
	if(strcmp(p1.id,p2.id)<0) return true;
	else return false;
}
int main(){
	//char t1[9];
	int n,l,h,i;
	scanf("%d%d%d",&n,&l,&h);
	person tmp;
	vector<person> persons;
	for(i=0;i<n;i++){
		scanf("%s %d %d",tmp.id,&tmp.Vgrade,&tmp.Tgrade);
		if(tmp.Vgrade>=l&&tmp.Tgrade>=l){
			if(tmp.Vgrade>=h){
				if(tmp.Tgrade>=h) 
					tmp.level=1;//sages
				else
					tmp.level=2;//noblemen
			}
			else{//Vgrade<h
				if(tmp.Tgrade<h&&tmp.Vgrade>=tmp.Tgrade)
					tmp.level=3;//foolmen
				else{
					tmp.level = 4;
				}
			}
			tmp.totalgrade = tmp.Vgrade+tmp.Tgrade;
			persons.push_back(tmp);
		}
	}
	sort(persons.begin(),persons.end(),cmp);
	printf("%d\n",persons.size());
	for(i=0;i<persons.size();i++){
		printf("%s %d %d\n",persons[i].id,persons[i].Vgrade,persons[i].Tgrade);
	}
}
