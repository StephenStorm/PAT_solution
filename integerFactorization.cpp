//2019.4.22
#include<stdio.h>
//#include<algorithm>
#include<math.h>
#include<vector>
using namespace std;
int n,p,k,maxfacsum=-1;
vector<int> tmpfac,res,fac;
void dfs(int index,int sum,int facsum,int ck){
	//ck  ָcurrent k ��ʾ��ǰ��kֵ 
	if(sum==n&&ck == k){
		if(facsum>maxfacsum){
			maxfacsum = facsum;
			res = tmpfac;
		}
		return;
	}
	if(sum>n||ck>k) return;
	if(index>0){
		//ѡȡindex 
		tmpfac.push_back(index);
		dfs(index,sum+fac[index],facsum+index,ck+1);//ѡȡindex����Ȼ�����ٴ�ѡȡindex 
		tmpfac.pop_back();//����ѡ�е�index�����в�ѡ��index�ķ�֧ 
		dfs(index-1,sum,facsum,ck);
	}
}
int main(){
	scanf("%d%d%d",&n,&k,&p);
	int i=0,tmp = 0;
	while(tmp<=n){
		fac.push_back(tmp);
		tmp = pow(++i,p);
	} 
	dfs(fac.size()-1,0,0,0);
	if(maxfacsum==-1){
		printf("Impossible");return 0;
	} 
	printf("%d =",n);
	for(i=0;i<res.size();i++){
		if(i!=0) printf(" +");
		printf(" %d^%d",res[i],p);
	} 
	return 0;
}
