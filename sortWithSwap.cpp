//2019.4.4
//�����ջ����ڣ�������������±꣬�����е�������������洢ÿ�����ֵ�λ��
//������˳��洢��������� 
#include<stdio.h>
#include<algorithm> 
#include<vector>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> pos(n);
	//pos���������洢�����ֵ�ǰ��λ���±� 
	int i,num,left = n-1;
	//left �����洢���ڱ�λ�ķ�0 ���ֵĸ��� 
	for(i=0;i<n;i++){
		scanf("%d",&num);
		pos[num] = i;
		if(num == i && num != 0)
			left--;
	}
	int k = 1,time=0;
	while(left>0){
		//���0��0λ�ã���Ѱ�ҵ�һ�����ڱ�λ�����ֺ�0���� 
		if(pos[0] == 0){
			while(k<n){//���ҵ�һ�����ڱ�λ������ 
				if(pos[k] != k){
					swap(pos[0],pos[k]);
					time++;
					break;
				} 
				k++;
			}
		}
		while(pos[0] != 0){
			swap(pos[0],pos[pos[0]]);
			time++;
			left--;
		} 
	}
	printf("%d",time);
	return 0;
}
