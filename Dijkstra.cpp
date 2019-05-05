//Dijkstra  �㷨�ܽ�
//2019.5.4
/* 
Dijkstra ���ָ��ӿ���
1��������Ȩ��Ҫ�����·���ж���ʱҪ��·���ϵĻ���֮����С
for(int v = 0; v < n; v++) { //��дv��forѭ��
  if(visit[v] == false && e[u][v] != inf) {
    if(dis[u] + e[u][v] < dis[v]) {
      dis[v] = dis[u] + e[u][v];
      c[v] = c[u] + cost[u][v];
    }else if(dis[u] + e[u][v] == dis[v] && c[u] + cost[u][v] < c[v]) {
      c[v] = c[u] + cost[u][v];
    }
  }
}
2������ÿ����ĵ�Ȩ������Emergency��Ҫ�����·���ж���ʱ��Ȩ֮�����
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
3�����ж��������·��
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
�������������Ҫ�� 
��Ҫ�����·������Ҫ���Ȩ��󣬻�Ҫ���·��������·�� 
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
	vector<bool> vis(n,0); //�Ƿ񱻷��ʹ� 
	vector<int> w(n),num(n),dis(n),pre(n);
	//wΪ����õ��teamNum������numΪ����õ��·������ ��dis[i]��ʾ����i�ڵ�����·������ 
	//preΪ��ǰ�ڵ��ǰ���ڵ�
	for(i=0;i<n;i++)pre[i]  = i;//��ǰ������ʼ��Ϊ���� 
	fill(dis.begin(),dis.end(),inf);
	dis[c1]=0;
	w[c1]=teamNum[c1];
	num[c1] = 1;
	int index;
	for(i=0;i<n;i++){
		int u = -1,minl = inf;
		for(j=0;j<n;j++){
		//��ѭ������Ѱ����һ��Ҫ���ʵĽڵ� 
			if(!vis[j]&&dis[j]<minl){
				minl = dis[j];
				u = j;
			}
		}
		if(u==-1) break;
		vis[u]=true;
		//�ڽӱ�洢 
		for(vector<pair<int,int> >::iterator it = link[u].begin();it!=link[u].end();it++){
			index = it->first;
			if(!vis[index]){
				if(dis[u]+(it->second)<dis[index]){
					//�����·������ 
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
