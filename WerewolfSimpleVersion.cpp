//2019.5.4
#include<stdio.h>
#include<math.h>
#include<vector>
using namespace std;
int main(){
	int n,i,j,k;
	scanf("%d",&n);
	vector<int> state(n+1);
	for(i=1;i<=n;i++)
		scanf("%d",&state[i]);
	//假设i，j是狼人 
	for(i=1;i<=n;i++){
		for(j=i+1;j<=n;j++){
			vector<int> flag(n+1,1),lie;
			//1表示对应下标是好人，-1表示对应下标是狼人 
			flag[i]=-1;
			flag[j]=-1;
			for(k=1;k<=n;k++){
				if(state[k]*flag[abs(state[k])]<0)
					//所说的话与事实不符合 
					lie.push_back(k);
			}
			if(lie.size()==2&&flag[lie[0]]+flag[lie[1]]==0){
				printf("%d %d\n",i,j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0; 
} 
