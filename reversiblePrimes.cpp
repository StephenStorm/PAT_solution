//2019.4.1
#include<stdio.h>
#include<vector>
using namespace std;
bool isPrime(int n){
    if(n==1) return false;
    if(n<=3) return true;
    for(int i=2;i<n;i++){
        if(n%i == 0) return false;
    }
    return true;
}
int main(){
    vector<int> dig;
    int n,d,i;
    bool flag;
    scanf("%d",&n);
    while(n>=0){
        scanf("%d",&d);
        if(!isPrime(n)){
            printf("No\n");
            scanf("%d",&n);
            continue;
        }
        while(n!=0){
            dig.push_back(n%d);
            n/=d;
        }
        int radix=1,sum = 0;
        for(i=dig.size()-1;i>=0;i--){
            sum+=radix*dig[i];
            radix*=d;
        }
        dig.clear();
        if(isPrime(sum)) printf("Yes\n");
        else printf("No\n");
        scanf("%d",&n);
    }
    return 0;
}
