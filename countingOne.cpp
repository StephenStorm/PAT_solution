//2019.4.9
//本程序是参考大神博客写成，并非原创
// 基本思想是累加每个数位出现 1 的次数即可得到答案
//设当前位为now，当前位左边的数字构成left，右边的数字构成right，则有如下三种情况
//a表示当前为个位，则为1，十位是 10，百位100，以此类推 
//now == 0  ans = left*a  
//因为now=0，left可取的值为0--left-1工left个数，而right有a（0--99...)中选择 
//now == 1，ans = left*a+right+1;
//第二种情况相比于第一种情况，多了now位为1 时的情形，此时right可取0--right，共right种可能 
//now>=2 ans = (left+1)*a
//此时left可取的值为0--left共left+1个数，而右边可取0--999...共a种选择 
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

