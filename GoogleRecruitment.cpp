//2019.5.1
//����һ���޴�ĿӾ�����������λ������k������Ҫ��ǰ�߲�0ֱ��λ���ﵽkλ
//������Ե� 2 ����ȥ������ 
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
	//��������㹻kλ 
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
