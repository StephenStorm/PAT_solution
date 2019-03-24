#include<stdio.h>
using namespace std;
int main(){
    long long a,b,c;
    int num;
    scanf("%d",&num);
    int i=0,j;
    bool flag;
    for(int j=0;j<num;j++){
        scanf("%lld%lld%lld",&a,&b,&c);
        long long result = a+b;
        if(a>0&&b>0&&result<0) flag = true;
        else if(a<0&&b<0&&result>=0) flag = false;
        else if(result>c) flag = true;
        else flag = false;
        if(flag) printf("Case #%d: true\n",++i);
        else printf("Case #%d: false\n",++i);
    }
    return 0;
}
