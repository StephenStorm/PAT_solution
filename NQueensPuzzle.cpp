//2019.5.12
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
int loc[1001];
int main(){
	int n,k,i,j,m;
	bool flag;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&k);
		for(m=0;m<k;m++)
			scanf("%d",&loc[m]);
		flag = true;
		for(m=1;m<k&&flag;m++){
			for(j=0;j<m;j++){
				if(loc[j]==loc[m]||abs(m-j)==abs(loc[j]-loc[m])){
					flag = false;
					printf("NO\n");
					break;
				}
			}
		}
		if(flag) printf("YES\n"); 
	}
}
