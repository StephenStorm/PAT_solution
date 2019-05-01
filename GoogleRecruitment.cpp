//2019.5.1
//本题一个巨大的坑就是如果结果的位数不足k，则需要在前边补0直至位数达到k位
//否则测试点 2 过不去！！！ 
#include<vector>
#include<stdio.h>
#include<math.h>
#include<string>
using namespace std;
bool isPrime(int n){
	if(n==0) return false;
	if(n<=2) return true;
	int j=int(sqrt(n));
	for(int i=2;i<=j;i++){
		if(n%i==0) return false;
	}
	return true;
} 
char str[10001];
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int l,k;
	scanf("%d %d",&l,&k);
	scanf("%s",str);
	if(l<k) {
		printf("404");
		return 0;
	} 
	int a=1,i;
	for(i=1;i<k;i++){
		a*=10;
	}
	int t1=1,tmp=0;
	for(i=k-2;i>=0;i--){
		tmp+=(str[i]-48)*t1;
		t1*=10;
	}
	string format="%0"+to_string(k)+"d";
	//控制输出足够k位 
	for(i=k-1;i<l;i++){
		tmp=tmp%a*10+str[i]-48;
		if(isPrime(tmp)) {
			printf(format.c_str(),tmp);
			return 0;
		}		
	}
	printf("404");
	return 0;
}
