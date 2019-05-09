//2019.5.5
#include<stdio.h>
#include<algorithm>
#include<cstring>
//输出语句后边的  句号 "  .  "一定要输出，害死人不偿命！！   
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
	scanf("%s",dig);
	if(isPalindrome(dig)) {
		printf("%s is a palindromic number.\n",dig);
		return 0;
	}
	int j=10,len,i,tmp,carry;
	while(j--){
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
		reverse_copy(dig,dig+len,tt);
		printf("%s + %s = %s\n",dig,tt,res);
		if(isPalindrome(res)){
			printf("%s is a palindromic number.\n",res);
			return  0;
		}
		strcpy(dig,res);	
	}
	printf("Not found in 10 iterations.\n");
	return 0;
}
