//2019.4.2
#include<iostream>
#include<string>
using namespace std;
int main(){
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    bool hashTable[128]={0};
    for(int i=0;i<128;i++) hashTable[i] = false;
    int len1 = s1.length();
    int len2 = s2.length();
    for(int i=0;i<len2;i++){
        hashTable[s2[i]] = true;
    }
    for(int i=0;i<len1;i++){
        if(hashTable[s1[i]]==false) printf("%c",s1[i]);
    }
    return 0;
}
