//2019.4.8
#include<stdio.h>
using namespace std;
int k[200005];
int main(){
    int n, m, temp, count = 0;
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &k[i]);
    k[n + 1] = 0x7fffffff;
    scanf("%d",&m); 
    int midpos = (n + m + 1) / 2, i = 1;
    for (int j = 1; j <= m; j++) {
        scanf("%d", &temp);
        while (k[i] < temp) {
            count++;
            if (count == midpos) printf("%d",k[i]);
            i++;
        }
        count++;
        //将tmp 合并至序列中 
        if (count == midpos) printf("%d",temp);
    }
    while (i <= n) {
        count++;
        if (count == midpos) printf("%d",k[i]);
        i++;
    }
    return 0;
}
/* 
int s1[200005],s2[200005];
int INF = 0x7fffffff;
int main(){
	int n1,n2,i,j;
	scanf("%d",&n1);
	for(i=0;i<n1;i++)
		scanf("%d",&s1[i]);
	scanf("%d",&n2);
	for(i=0;i<n2;i++){
		scanf("%d",&s2[i]);
	}
	int count = 0;
	int mid = (n1+n2-1)/2;
	s1[n1] = s2[n2] = INF;
	i=0;
	j=0;
	while(count < mid){
		if(s1[i]<s2[j]) i++;
		else j++;
		count++;
	}
	if(s1[i]<s2[j]){
		printf("%d",s1[i]); 
	}
	else
		printf("%d",s2[j]);
	return 0;
}
*/
