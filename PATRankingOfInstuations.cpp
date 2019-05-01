//2019.4.30
#include<vector>
#include<iostream>
#include<cstring>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
struct school{
	int tws;
	int ns;
	string name;
	int rank;
};
bool cmp(school s1,school s2){
	if(s1.tws!=s2.tws) return s1.tws>s2.tws;
	else{
		if(s1.ns!=s2.ns) return s1.ns<s2.ns;
		return s1.name<s2.name;
	}
}
//按照tws，ns，name的优先级进行排序 
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	int score,i;
	char sch[7],id[7];
	unordered_map<string, int[4]> pre;
	//不需要排序功能，用unordered_map节省时间 
	for(i=0;i<n;i++){
		scanf("%s %d %s",id,&score,sch);
		transform(sch,sch+strlen(sch),sch,::tolower);
		if(id[0]=='A') pre[sch][0]+=score;
		else{
			if(id[0]=='B') pre[sch][1]+=score;
			else pre[sch][2]+=score;
		}
		pre[sch][3]++;
	}//用map过滤掉重复的值 
	int count =  pre.size();
	vector<school> list(count);
	i=0;
	for(unordered_map<string,int[4]>::iterator it=pre.begin();it!=pre.end();it++){
		list[i].name = it->first;
		list[i].tws = int(it->second[0]+float(it->second[1])/1.5+float(it->second[2])*1.5);
		list[i].ns = it->second[3];
		i++;
	}//用vector保存整理后的结果 
	sort(list.begin(),list.end(),cmp);
	//排序 
	list[0].rank = 1;
	for(i=1;i<count;i++){
		if(list[i].tws==list[i-1].tws) list[i].rank=list[i-1].rank;
		else list[i].rank = i+1;
	}//排名 
	printf("%d\n",count);
	for(i=0;i<count;i++){
		printf("%d %s %d %d\n",list[i].rank,list[i].name.c_str(),list[i].tws,list[i].ns);
	}
	return 0; 
} 
