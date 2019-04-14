//2019.4.14
//hashtable ·½·¨ 
#include<stdio.h>
using namespace std;
int num[10000]={0};
bool isPrime(int a){
	if(a<=2) return true;
	for(int i=2;i*i<=a;i++){
		if(a%i==0) return false;
	}
	return true;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int i,n,tmp;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		num[tmp] = i+1;
	}
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&tmp);
		switch(num[tmp]){
			case -1:
				printf("%04d: Checked\n",tmp);
				break;
			case 0:
				printf("%04d: Are you kidding?\n",tmp);
				break;
			case 1:
				printf("%04d: Mystery Award\n",tmp);
				num[tmp] = -1;
				break;
			default:
				if(isPrime(num[tmp])){
						printf("%04d: Minion\n",tmp);
				} 
				else  printf("%04d: Chocolate\n",tmp);
				num[tmp] = -1;
		};
	} 
} 
