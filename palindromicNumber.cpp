//2019.5.14
#include<stdio.h>
#include<algorithm>
#include<cstring>
//本题与前边一道题目  delayedPalindromic  故本题将原来代码稍加修改直接使用   
using namespace std;
char dig[1010],tt[1010],res[1010];
bool isPalindrome(char str[]){
	int j=strlen(str)-1;
	int i=0;
	while(i<=j&&str[i]==str[j]){
		i++;
		j--;
	}
	if(i>j)return true;
	return false;
}
int main(){
	int k;
	scanf("%s %d",dig,&k);
	if(isPalindrome(dig)) {
		printf("%s\n0",dig);
		return 0;
	}
	int j,len,i,tmp,carry;
	for(j=0;j<k;j++){
		len = strlen(dig);
		carry = 0;
		for(i=0;i<len;i++){
			tmp=carry+dig[i]+dig[len-1-i]-96;
			if(tmp>9){
				carry=1;
				res[i] = tmp-10+48;
			}
			else{
				carry = 0;
				res[i] = tmp+48;
			}
		}
		if(carry==1)
			res[i]=49;
		else res[i] = 0;
		reverse(res,res+strlen(res));
		if(isPalindrome(res)){
			printf("%s\n",res);
			printf("%d",j+1);
			return  0;
		}
		strcpy(dig,res);	
	}
	printf("%s\n%d",res,k);
	return 0;
}
