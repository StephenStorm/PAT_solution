//2019.5.4
#include<stdio.h>
#include<vector>
#include<utility>
#include<stack>
using namespace std;
int inf=99999999;
int main(){
	int n,m,c1,c2,i,j,t1,t2,l;
	scanf("%d%d%d%d",&n,&m,&c1,&c2);
	vector<int> teamNum(n);
	for(i=0;i<n;i++){
		scanf("%d",&teamNum[i]);
	}
	vector<vector<pair<int,int> > > link(n);
	for(i=0;i<m;i++){
		scanf("%d%d%d",&t1,&t2,&l);
		link[t1].push_back(make_pair(t2,l));
		link[t2].push_back(make_pair(t1,l));
	}
	vector<bool> vis(n,0); //是否被访问过 
	vector<int> w(n),num(n),dis(n);
	//w为到达改点的teamNum数量，num为到达改点的路径个数 ，num[i]表示到达i节点的最短路径长度 
	fill(dis.begin(),dis.end(),inf);
	dis[c1]=0;
	w[c1]=teamNum[c1];
	num[c1] = 1;
	int index;
	for(i=0;i<n;i++){
		int u = -1,minl = inf;
		for(j=0;j<n;j++){
		//该循环用于寻找下一个要访问的节点 
			if(!vis[j]&&dis[j]<minl){
				minl = dis[j];
				u = j;
			}
		}
		if(u==-1) break;
		vis[u]=true;
		for(vector<pair<int,int> >::iterator it = link[u].begin();it!=link[u].end();it++){
			index = it->first;
			if(!vis[index]){
				if(dis[u]+(it->second)<dis[index]){
					//以最短路径优先 
					dis[index]=dis[u]+it->second;
					num[index] = num[u];
					w[index] = w[u]+teamNum[index]; 
				}
				else{
					if(dis[u]+(it->second)==dis[index]){
						num[index]=num[u]+num[index];
						if(w[u]+teamNum[index]>w[index])
							w[index] = w[u]+teamNum[index];
					}
				}
			}
		} 
	} 
	printf("%d %d",num[c2],w[c2]);
} 
