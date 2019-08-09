//2019.8.9
//https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(long long a,long long b){
	if(b == 0) return a;
	return gcd(b,a%b);
}
struct Fraction{
	long long up,down;
};
Fraction reduction(Fraction f){
	if(f.down<0) {
		f.up = -f.up;
		f.down = -f.down;
	}
	if(f.up == 0) f.down = 1;
	else{
		long long d = gcd(abs(f.up),f.down);
		f.up /= d;
		f.down /= d;
	} 
	return f;	
}
void showResult(Fraction f1){
	if(f1.down == 0) {
		printf("Inf");
		return;
	}
	Fraction f=reduction(f1);
	if(f.up<0) printf("(");
	if(f.down ==1 ) printf("%lld",f.up);
	else{
		if(abs(f.up) > f.down){
			printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
			
		}
		else{
			printf("%lld/%lld",f.up,f.down);
		}
	}
	if(f.up<0) printf(")");
}
Fraction add(Fraction f1,Fraction f2){
	Fraction r;
	r.down = f1.down*f2.down;
	r.up = f1.up*f2.down+f2.up*f1.down;
//	showResult(r);
	return reduction(r);

}
Fraction sub(Fraction f1,Fraction f2){
	Fraction r;
	r.down = f1.down*f2.down;
	r.up = f1.up*f2.down -f2.up*f1.down;
	return reduction(r);
}
Fraction mul(Fraction f1,Fraction f2){
	Fraction r;
	r.up = f1.up*f2.up;
	r.down = f1.down*f2.down;
	return reduction(r);
}
Fraction div(Fraction f1,Fraction f2){
	Fraction r;
	r.up = f1.up*f2.down;
	r.down = f1.down*f2.up;
	return reduction(r);
}
int main(){
	
	Fraction f1,f2;
	scanf("%lld/%lld",&f1.up,&f1.down);
	scanf("%lld/%lld",&f2.up,&f2.down);
	showResult(f1);printf(" + ");showResult(f2);printf(" = ");showResult(add(f1,f2)); printf("\n");
	showResult(f1);printf(" - ");showResult(f2);printf(" = ");showResult(sub(f1,f2));printf("\n");
	showResult(f1);printf(" * ");showResult(f2);printf(" = ");showResult(mul(f1,f2));printf("\n");
	showResult(f1);printf(" / ");showResult(f2);printf(" = ");showResult(div(f1,f2));
	
}
