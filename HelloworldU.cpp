//2019.3.22  start 23.35
#include<iostream>
#include<string>
using namespace std;
int main(){
    string str;
    cin>>str;
    int len = str.length();
    int n1 = (len+2)/3;
    int n2 = len+2-2*n1;
    int white = n2-2;
    int i;
    for(i=0;i<n1-1;i++){
        cout<<str[i];
        for(int j=0;j<white;j++) cout<<" ";
        cout<<str[len-i-1]<<endl;
    }
    while(n2>0){
        cout<<str[i++];
        n2--;
    }
}
