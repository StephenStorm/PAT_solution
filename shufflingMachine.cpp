//2019.4.12
#include<iostream>
#include<string>
using namespace std;
int main(){
	int times,rule[55],i,j;
	cin>>times;
	for(i=1;i<55;i++){
		scanf("%d",&rule[i]);
	}
	string card[55]={"0","S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",\
					  "H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",\
					  "C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",\
					  "D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",\
					  "J1","J2"};
	int index[2][55];
	for(i=1;i<55;i++){
		index[1][i] = i;
	}
	int fir;
	for(i=0;i<times;i++){
		//交替使用两个索引数组作为原数组 
		fir = i%2;
		for(j=1;j<55;j++){
			index[fir][rule[j]] = index[1-fir][j];
		}
	}
	cout<<card[index[fir][1]];
	for(i=2;i<55;i++){
		cout<<" "<<card[index[fir][i]];
	}
} 
