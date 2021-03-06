//Dijkstra  算法总结
//2019.5.4
/* 
Dijkstra 三种附加考法
1、新增边权，要求最短路径有多条时要求路径上的花费之和最小
for(int v = 0; v < n; v++) { //重写v的for循环
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      c[v] = c[u] + cost[u][v];
    }else if(dis[u] + e[u][v] == dis[v] && c[u] + cost[u][v] < c[v]) {
      c[v] = c[u] + cost[u][v];
    }
  }
}
2、给定每个点的点权（例如Emergency）要求最短路径有多条时点权之和最大
for(int v = 0; v < n; v++) {
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      w[v] = w[u] + weight[v];
    }else if(dis[u] + e[u][v] == dis[v] && w[u] + weight[v] > w[v]) {
      w[v] = w[u] + weight[v];
    }
  }
}
3、问有多少条最短路径
for(int v = 0; v < n; v++) {
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      num[u] = num[v];
    }else if(dis[u] + e[u][v] == dis[v]) {
      num[v] = num[v] + num[u];
    }
  }
}
本程序包括以下要求 
既要求最短路径，有要求点权最大，还要输出路径个数和路径 
*/ 

#include<stdio.h>
#include<vector>
#include<utility>
#include<stack>
using namespace std;
int inf=99999999;
void printPath(int);
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
	vector<int> w(n),num(n),dis(n),pre(n);
	//w为到达该点的teamNum数量，num为到达该点的路径个数 ，dis[i]表示到达i节点的最短路径长度 
	//pre为当前节点的前驱节点
	for(i=0;i<n;i++)pre[i]  = i;//将前驱结点初始化为自身 
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
		//邻接表存储 
		for(vector<pair<int,int> >::iterator it = link[u].begin();it!=link[u].end();it++){
			index = it->first;
			if(!vis[index]){
				if(dis[u]+(it->second)<dis[index]){
					//以最短路径优先 
					pre[index]=u; 
					dis[index]=dis[u]+it->second;
					num[index] = num[u];
					w[index] = w[u]+teamNum[index]; 
				}
				else{
					if(dis[u]+(it->second)==dis[index]){
						num[index]=num[u]+num[index];
						if(w[u]+teamNum[index]>w[index])
							w[index] = w[u]+teamNum[index];
							pre[index]=u;
					}
				}
			}
		} 
	} 
	printf("%d %d",num[c2],w[c2]);
	printPath(c2);
}  
void printPath(int v){
	if(v==c1){
		printf("%d",v);
		return;
	}
	printPath(pre[v]);
	printf("%d ",v);
}
