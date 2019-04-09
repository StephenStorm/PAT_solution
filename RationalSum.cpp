//2019.4.9
#include<stdio.h>
#include<vector>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	ll d = gcd(a,b);
	return a/d*b; 
}
int main(){
	long n,i;
	scanf("%d",&n);
	vector<long> num(n);
	vector<long> den(n);
	for(i=0;i<n;i++){
		scanf("%ld/%ld",&num[i],&den[i]);
	}
	long long sum1 = num[0],sum2 = den[0],minmu,mind;
	for(i=1;i<n;i++){
		minmu = lcm(sum2,den[i]);
		sum1 = sum1*(minmu/sum2)+num[i]*(minmu/den[i]);
		mind = gcd(sum1,minmu);
		sum1 = sum1/mind;
		sum2 = minmu/mind;
	}
	ll res = sum1/sum2;
	ll num1 = sum1%sum2;
	if(res == 0&& num1==0){
		printf("0");
		return 0;
	} 
	if(res != 0){
		printf("%ld",res);
		if(num1!=0) printf(" ");
	}
	if(num1!=0)printf("%ld/%ld",num1,sum2);
	return 0;
} 
