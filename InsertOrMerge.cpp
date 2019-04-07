//2019.4.7
//本题中只是做到模拟归并排序，并没有真正实现merge方法，即合并两个子序列
//而是直接使用了sort函数 
//首先判断是不是insertSort，如果是，则输出，否则输出mergeSort 的结果 
#include<stdio.h>
#include<algorithm>
using namespace std;
int *ori,*res,*changed,num;
bool isequal(int *a,int *b){
	for(int i=0;i<num;i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
bool insertSort(){
	int j,k;
	for(j=0;j<num;j++)
		changed[j] = ori[j];
	bool flag = false;
	for(j=1;j<num;j++){
		if(j!=1 && isequal(changed,res))
			flag = true;
		k = j-1;
		int tmp = changed[j];
		while(k>=0 && changed[k]>tmp){
			changed[k+1] = changed[k];
			k--;
		}
		changed[k+1] = tmp;
		if(flag)
			return true;
	}	
	return false;
}
void mergeSort(){
	bool flag = false;
	for(int step = 2;step/2<=num;step*=2){
		if(step != 2 && isequal(changed,res)){
			flag = true;
		}
		for(int i=0;i<num;i+=step){
			sort(changed+i,changed+min(i+step,num));
		}
		if(flag){
			printf("%d",changed[0]);
			for(int j=1;j<num;j++)
				printf(" %d",changed[j]);
			return;
		}
	}
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	scanf("%d",&num);
	ori = new int[num];
	res = new int[num];
	changed = new int[num];
	int i;
	for(i=0;i<num;i++)
		scanf("%d",&ori[i]);
	for(i=0;i<num;i++)
		scanf("%d",&res[i]);
	if(insertSort()){
		printf("Insertion Sort\n");
		printf("%d",changed[0]);
			for(int j=1;j<num;j++)
				printf(" %d",changed[j]);
	}
	else{
		printf("Merge Sort\n"); 
		for(i=0;i<num;i++){
			changed[i] = ori[i];
		}
		mergeSort();
	}
	delete[] ori;
	delete[] res;
	delete[] changed;
	return 0;
} 
