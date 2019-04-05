//2019.4.4
//最大的收获在于，灵活运用数组下标，本题中的数组就是用来存储每个数字的位置
//而不是顺序存储输入的数据 
#include<stdio.h>
#include<algorithm> 
#include<vector>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> pos(n);
	//pos数组用来存储各数字当前的位置下标 
	int i,num,left = n-1;
	//left 用来存储不在本位的非0 数字的个数 
	for(i=0;i<n;i++){
		scanf("%d",&num);
		pos[num] = i;
		if(num == i && num != 0)
			left--;
	}
	int k = 1,time=0;
	while(left>0){
		//如果0在0位置，则寻找第一个不在本位的数字和0交换 
		if(pos[0] == 0){
			while(k<n){//查找第一个不在本位的数字 
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
