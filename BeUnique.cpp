//2019.4.2
//一定要根据体重给定的数据范围准确确定数组的大小 防止数据越界访问
#include<stdio.h>
#include<vector>
using namespace std;

int hashTable[10001]={0};
int order[100001];
int main(){
    #ifdef ONLINE_JUDGE
    #else
        freopen("in.txt","r",stdin);
    #endif // ONLINE_JUDGE
    int num;
    scanf("%d",&num);
    int i;
    for(i=0;i<num;i++){
        scanf("%d",&order[i]);
        hashTable[order[i]]++;
    }
    for(i=0;i<num;i++){
        if(hashTable[order[i]]==1) {
            printf("%d",order[i]);
            return 0;
        }
    }
    printf("None");
    return 0;
}
