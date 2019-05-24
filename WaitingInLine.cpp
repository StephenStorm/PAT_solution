//2019.5.24
//使用优先队列快速解题 
#include<stdio.h>
#include<queue>
#include<utility>
using namespace std; 
int m;
struct windows{
	queue<pair<int,int> > line;
	int serveTime;//下次完成时间 
	int id;
	friend bool operator < (windows w1,windows w2){
		if(w1.line.size()!=w2.line.size()) return w1.line.size()>w2.line.size();
		//选择长度最小的 
		else{
			if(w1.line.size()==m){
				//两个长度都相等并且为m 选择最早结束的 
				if(w1.serveTime!=w2.serveTime) return w1.serveTime>w2.serveTime;
				else{
					return w1.id>w2.id;
				}
			}
			else return w1.id>w2.id;
		}
	}
};
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n,k,q,i,tmp,tmp2,hh,mm;
	windows w1;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	priority_queue<windows,vector<windows> > que;
	int low = 8*60,high=17*60;
	for(int i=1;i<=n;i++){
		w1.id=i;
		w1.serveTime=low;
		que.push(w1);
	} 
	vector<int> time(k+1),input(k+1);
	for(int i=1;i<=k;i++){
		scanf("%d",&tmp);
		input[i]=tmp;
		w1=que.top();
		que.pop();
		if(w1.line.size()==m){
			 time[w1.line.front().first]=w1.serveTime;
			 w1.line.pop();
			 if(!w1.line.empty())
			 	w1.serveTime+=w1.line.front().second;
		}
		if(w1.line.size()==0) w1.serveTime += tmp;
		w1.line.push(make_pair(i,tmp));
		que.push(w1);
	}
	while(!que.empty()){
		w1=que.top();
		while(!w1.line.empty()){
			time[w1.line.front().first]=w1.serveTime;
			w1.line.pop();
			if(!w1.line.empty())
			 	w1.serveTime+=w1.line.front().second;
		}
		que.pop();
	}
	/*
	for(int i=1;i<=k;i++){
		tmp = time[i];
		hh=tmp/60;
		mm=tmp%60;
		printf("%02d:%02d\n",hh,mm);
	}
	printf("\n");
	*/
	for(i=0;i<q;i++){
		scanf("%d",&tmp2);
		tmp = time[tmp2];
		hh=tmp-input[tmp2];
		if(hh>=high) printf("Sorry\n");
		else{
			hh=tmp/60;
			mm=tmp%60;
			printf("%02d:%02d\n",hh,mm);
		}
	}
	
}
