//2019.4.15
#include<iostream>
#include<cstring>
using namespace std;
int main(){
	#ifdef ONLINE_JUDGE
	#else
		freopen("in.txt","r",stdin);
	#endif
	string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
	string high[13]={"tret","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
	int n,i,j,sum;
	scanf("%d",&n);
	getchar();
	string str,t1,t2;
	int dig[2];
	for(i=0;i<n;i++){
		getline(cin,str);
		if(str[0]>='0'&&str[0]<='9'){
			//Êý×Ö×ª»»³É×Ö·û´®
			sscanf(str.c_str(),"%d",&sum);
			if(sum==0){
				printf("tret\n");continue;
				
			}
			j=0;
			while(sum!=0){
				dig[j++]=(sum%13);
				sum/=13;
			}
			if(j==2){
				cout<<high[dig[1]];
				if(dig[0]!=0)
					cout<<" "<<low[dig[0]];
				cout<<endl;
			}
			else	cout<<low[dig[0]]<<endl;
		}
		else{
			//×Ö·û´®×ªÊý×Ö
			sum = 0; 
			if(str.length()>4){
				j=3;
				while(str[j]!=' ') j++;
				t1=str.substr(0,j);
				t2=str.substr(j+1);
				for(j=0;j<13;j++){
					if(t1==high[j]) sum+=j*13;
					if(t2==low[j]) sum+=j;
				}
			}
			else{
				for(j=0;j<13;j++){
					if(str==low[j]){
						sum+=j;break;
					}
					if(str == high[j]){
						sum+=j*13;break;
					}
				}
			}
			printf("%d\n",sum);
		} 
	}
}
