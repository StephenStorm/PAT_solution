//2019.4.3
//贪心 + 模拟
//这道题目花费了大量时间，以我目前的水平来说是比较耗时的一道题目，希望日后再刷时可以改善，尽量提高速度 
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
struct station{
	float price;
	float distance;
	
};
bool cmp(station s1,station s2){
	return s1.distance<s2.distance;
}
int main(){
	#ifdef	ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	float cmax,dis,davg;
	int n;
	scanf("%f %f %f %d",&cmax,&dis,&davg,&n);
	vector<station> stas(n+1);
	int i,j;
	for(i=0;i<n;i++){
		scanf("%f %f",&stas[i].price,&stas[i].distance);
	} 
	stas[n].price = 0;
	stas[n].distance = dis; 
	//对所有加油站按照距离从小到大进行排序
	sort(stas.begin(),stas.end(),cmp);
	if(stas[0].distance!=0){
		printf("The maximum travel distance = 0.00");
		return 0;
	} 
	float pass = 0, cost = 0, maxdis = cmax*davg,left = 0,inc,minPrice;
	int current=0,minIndex;
	while(current<n){
		i=current + 1;
		minIndex = i;
		minPrice = stas[i].price;
		if(stas[i].distance>pass+maxdis){//满箱油不能到达下一目的地 
			printf("The maximum travel distance = %.2f",pass+maxdis);
			return 0;
		}
		while(i<=n&&stas[i].distance<=pass+maxdis){
			if(stas[i].price<stas[current].price){//找到第一个小于当前加油站价格的加油站
				minPrice = stas[i].price;
				minIndex = i;
				break;
			}
			if(stas[i].price<minPrice){
				minPrice = stas[i].price;
				minIndex = i;
			} 
			i++;
		}
		float tmp = (stas[minIndex].distance-pass)/davg;
		if(minPrice>stas[current].price){  //未找到比当前加油站价格更低的下一加油站 
			inc = cmax - left;
			left = 	cmax - tmp;
		}
		else{//找到更低价格的加油站 
			if(tmp>left){//如果剩下的油不能到达下一加油站，则添加到恰好可以到达 
				inc = tmp-left;
				left = 0;
			}
			else{//剩下的油可以到达下一加油站，不用加油，只修改剩余油量 
				inc = 0;
				left -= tmp;
			}
		} 
		cost += inc*(stas[current].price);
		current = minIndex;
		pass = stas[current].distance;
	}
	printf("%.2f",cost);
} 
