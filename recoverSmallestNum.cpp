//2019.4.5
//�����Ŀ��������ǰ������ַ������бȽϵķ�ʽ �һ��ǱȽ��гɾ͸е�
//�Ͼ����˴����ͻȻ����  �������ֱȽϷ�ʽ�ȼ� ��������� 
#include<stdio.h>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct num{
	char dig[9];
};
bool cmp(num n1,num n2){
	char tmp1[17],tmp2[17];
	strcpy(tmp1,n1.dig);
	strcat(tmp1,n2.dig);
	strcpy(tmp2,n2.dig);
	strcat(tmp2,n1.dig);
	return strcmp(tmp1,tmp2)<0?true:false;
}
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	int n;
	scanf("%d",&n);
	int i = 0;
	vector<num> vec(n);
	for(i=0;i<n;i++){
		scanf("%s",&vec[i]);
	}
	sort(vec.begin(),vec.end(),cmp);
	bool flag = false;
	int j=0;
	while(j<n&&!flag){
		i=0;
		while(i<strlen(vec[j].dig)&&vec[j].dig[i] == 48)
			i++;
		while(i<strlen(vec[j].dig)) {
			printf("%c",vec[j].dig[i]);
			flag = true;
			i++;
		}
		j++;
	}
	if(j==n){//ȫ��0�����  ��Ӧ����Ե�2  ���� 
		printf("0");
		return 0;
	}
	for(i=j;i<n;i++){
		printf("%s",vec[i].dig);
	}
	return 0;
} 
