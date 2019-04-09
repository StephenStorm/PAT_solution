//2019.4.9
//此处用到一个定理：
// 如果step从0~size-1 进行枚举仍然无法找到位置，那么对于step>=size来说也找不到位置 
#include<stdio.h>
#include<vector>
#include<math.h>
using namespace std;
bool isPrime(int a){
	if(a<2) return false;
	int sqr = (int)sqrt(1.0*a);
	for(int i=2;i<=sqr;i++){
		if(a%i == 0) return false;
	}
	return true;
} 
int main(){
	int size,n;
	scanf("%d",&size);
	while(!isPrime(size)) size++;
	vector<bool> pos(size);
	int step,tmp,index;
	scanf("%d",&n);
	scanf("%d",&tmp);
	pos[tmp%size]=true;
	printf("%d",tmp%size);
	for(int i=1;i<n;i++){
		scanf("%d",&tmp);
		step = 0;
		index = (tmp+step*step)%size;
		while(pos[index]&&step<size){
			step++;
			index = (tmp+step*step)%size;
		}
		if(step == size) printf(" -");
		else{
			pos[index]=true;
			printf(" %d",index);
		}
	}
}
