//2019.4.2
//һ��Ҫ�������ظ��������ݷ�Χ׼ȷȷ������Ĵ�С ��ֹ����Խ�����
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
