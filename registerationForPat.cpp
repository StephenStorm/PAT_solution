//2019.5.3
//解答本题时，选择为了时间放弃空间的做法，为了快速查询，选择了多种存储方式 
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
struct testee{
	char id[14];
	int score;
};
struct rec{
	int site,num;
};
bool cmp(testee t1,testee t2){
	if(t1.score!=t2.score) return t1.score>t2.score;
	return strcmp(t1.id,t2.id)<0?true:false;
}
bool cmp2(rec r1,rec r2){
	if(r1.num!= r2.num)return r1.num>r2.num;
	return r1.site<r2.site;
}
int total[1000][2];
//0 存储人数，1 存储总分 
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	map<char,vector<testee> > map1;
	map<string,vector<int> > timeMap; 
	int n,m,i,j,tmp,ss;
	scanf("%d%d",&n,&m);
	char site[4],time[7],ch;
	testee tt;
	for(i=0;i<n;i++){
		scanf("%s %d",tt.id,&tt.score);
		for(j=0;j<3;j++){
			site[j] = tt.id[j+1];
		}
		sscanf(site,"%d",&ss);
		for(j=0;j<6;j++){
			time[j] = tt.id[j+4];
		}
		timeMap[time].push_back(ss); 
		total[ss][0]++;
		total[ss][1]+=tt.score;
		ch = tt.id[0];
		map1[ch].push_back(tt);
	}
	for(map<char,vector<testee> >::iterator it=map1.begin();it!=map1.end();it++){
		sort(it->second.begin(),it->second.end(),cmp);
	}
	vector<rec> res3;
	rec rr;
	int count[1000];
	for(i=0;i<m;i++){
		scanf("%d %s",&tmp,time);//此处复用time字符数组接受选项
		printf("Case %d: %d %s\n",i+1,tmp,time);
		switch(tmp){
			case 1:
				ch = time[0];
				if(map1[ch].size()==0){
					printf("NA\n");
					break;
				}
				for(j=0;j<map1[ch].size();j++){
					printf("%s %d\n",map1[ch][j].id,map1[ch][j].score);
				}
				break;
			case 2:
				sscanf(time,"%d",&ss);
				if(total[ss][0]==0) printf("NA\n");
				else printf("%d %d\n",total[ss][0],total[ss][1]);
				break;
			case 3:
				if(timeMap[time].size()==0) {
					printf("NA\n");break;
				}
				memset(count,0,sizeof(count));
				for(vector<int>::iterator it= timeMap[time].begin();it!=timeMap[time].end();it++){
					count[*it]++;
				}
				for(j=101;j<1000;j++){
					if(count[j]!=0){
						rr.num=count[j];
						rr.site = j;
						res3.push_back(rr);
					}
				}
				sort(res3.begin(),res3.end(),cmp2);	
				for(j=0;j<res3.size();j++){
					printf("%d %d\n",res3[j].site,res3[j].num);
				}
				res3.clear();
				break;			
		}	
	}
} 
