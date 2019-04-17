//2019.4.16
#include<stdio.h>
#include<stack>
#include<vector>
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int m,n,k,tmp,s,j;
	bool flag;
	scanf("%d%d%d",&m,&n,&k);
	stack<int> stk;
	vector<int> vec(n);
	for(int i=0;i<k;i++){
		for(j=0;j<n;j++){
			scanf("%d",&vec[j]);
		}
		flag =false;
		s=0; 
		for(j=1;j<=n;j++){
			stk.push(j);
			if(stk.size()>m){
				flag = true;
				break;
			}
			while(!stk.empty()&&stk.top() == vec[s]){
				s++;
				stk.pop();
			}
		}
		if(!flag&&stk.empty()) printf("YES\n");
		else {
			printf("NO\n");
			while(!stk.empty()) stk.pop();
		}
	}
}
