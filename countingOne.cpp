//2019.4.9
//�������ǲο����񲩿�д�ɣ�����ԭ��
// ����˼�����ۼ�ÿ����λ���� 1 �Ĵ������ɵõ���
//�赱ǰλΪnow����ǰλ��ߵ����ֹ���left���ұߵ����ֹ���right�����������������
//a��ʾ��ǰΪ��λ����Ϊ1��ʮλ�� 10����λ100���Դ����� 
//now == 0  ans = left*a  
//��Ϊnow=0��left��ȡ��ֵΪ0--left-1��left��������right��a��0--99...)��ѡ�� 
//now == 1��ans = left*a+right+1;
//�ڶ����������ڵ�һ�����������nowλΪ1 ʱ�����Σ���ʱright��ȡ0--right����right�ֿ��� 
//now>=2 ans = (left+1)*a
//��ʱleft��ȡ��ֵΪ0--left��left+1���������ұ߿�ȡ0--999...��a��ѡ�� 
#include<stdio.h>
#include<cstring>
using namespace std;

int main(){
	int n,left,now,right,a=1;
	scanf("%d",&n);
	int count = 0;
	while(n/a){
		left = n/(a*10);
		now = n/a%10;
		right = n%a;
		if(now == 0) count+=left*a;
		else if(now == 1) count+=left*a+right+1;
		else count+=(left+1)*a;
		a*=10;
	}
	printf("%d",count);
}

