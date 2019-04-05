//2019.4.3
//�����Ŀ�����˴���ʱ�䣬����Ŀǰ��ˮƽ��˵�ǱȽϺ�ʱ��һ����Ŀ��ϣ���պ���ˢʱ���Ը��ƣ���������ٶ� 
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
		if(stas[i].distance>pass+maxdis){//�����Ͳ��ܵ�����һĿ�ĵ� 
			printf("The maximum travel distance = %.2f",pass+maxdis);
			return 0;
		}
		while(i<=n&&stas[i].distance<=pass+maxdis){
			if(stas[i].price<stas[current].price){
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
		if(minPrice>stas[current].price){  //δ�ҵ��ȵ�ǰ����վ�۸���͵���һ����վ 
			inc = cmax - left;
			left = 	cmax - tmp;
		}
		else{//�ҵ����ͼ۸�ļ���վ 
			if(tmp>left){//���ʣ�µ��Ͳ��ܵ�����һ����վ������ӵ�ǡ�ÿ��Ե��� 
				inc = tmp-left;
				left = 0;
			}
			else{//ʣ�µ��Ϳ��Ե�����һ����վ�����ü��ͣ�ֻ�޸�ʣ������ 
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
