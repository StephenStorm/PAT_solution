//2019.5.11
//�������ȶ��У��ܹ�ÿ��ȡ�� ������Է���Ĵ��� 
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
struct cus{
	int arr,pro;
};
bool cmp(cus c1,cus c2){
	return c1.arr<c2.arr;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif 
	int n,k,i,hh,mm,ss,tp,tmp,count=0;
	scanf("%d %d",&n,&k);
	int sumTime = 0,low=8*3600,high=17*3600;
	vector<cus> cuss(n);
	for(i=0;i<n;i++){
		scanf("%d:%d:%d %d",&hh,&mm,&ss,&tp);
		tmp=hh*3600+mm*60+ss;
		if(tmp>high) continue;
		cuss[count].arr = tmp;
		cuss[count++].pro = tp;
	}
//	if(count==0) {
//		printf("0");
//		return 0;
//	}
//�����ԣ����ÿ��� ����ʱ����û�пͻ������ 
	sort(cuss.begin(),cuss.begin()+count,cmp);
	priority_queue<int,vector<int>,greater<int> > que;
	for(i=0;i<k;i++)
		que.push(low);
	for(i=0;i<count;i++){
		tmp = que.top();
		que.pop();
		if(tmp>cuss[i].arr){
			sumTime+=(tmp-cuss[i].arr);//�ȴ�ʱ��
			que.push(tmp+cuss[i].pro*60);//�´η���ʱ�����
		}
		else que.push(cuss[i].arr+cuss[i].pro*60);
	}
	float res = (float)sumTime/count/60;
	printf("%.1f",res); 
} 
