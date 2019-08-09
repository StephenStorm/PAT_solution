//2019.8.9
//https://pintia.cn/problem-sets/994805342720868352/problems/994805415005503488
#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
const int maxn = 100010;
int Pri[maxn],count=0;
struct factor{
	int x;
	int cnt;
};
bool isPrime(long long n){
	if(n<=1) return false;
	long long i;
	for(i=2;i*i<=n;i++){
		if(n%i==0) return false;
	}
	return true;
}
void getPrime(){
	for(int i=0;i<maxn;i++){
		if(isPrime(i)) Pri[count++] = i;
	}	
}
int main(){
	getPrime();
	long long n;
	scanf("%lld",&n);
	if(n==1) printf("1=1");
	else{
		vector<factor> fac;
		printf("%lld=",n);
		int sqr = (int)sqrt(1.0*n);
		for(int i=0;i<sqr;i++){
			if(n%Pri[i]==0){
				factor f={Pri[i],0};
				while(n%Pri[i]==0) {
					f.cnt++;
					n/=Pri[i];	
				}
				fac.push_back(f);
			}
			if(n==1)  break;
		}
		if(n!=1){
			factor f={(int)n,1};
			fac.push_back(f);
		}
		for(int i=0;i<fac.size();i++){
			if(i>0) printf("*");
			printf("%d",fac[i].x);
			if(fac[i].cnt!=1) printf("^%d",fac[i].cnt);
		}
	} 
}
