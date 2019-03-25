//2019 3.25 start time:17:59  actime:18:40
#include<stdio.h>
using namespace std;
int main(){
    int num,i,changedNum=0;
    bool modified=false;
    bool flag  = false;
    scanf("%d",&num);
    char **names = new char*[num];
    char **passwd = new char*[num];
    int *changed = new int[num];
    for(i=0;i<num;i++){
        names[i] = new char[11];
        passwd[i] = new char[11];
        changed[i] = false;
    }
    for(int j=0;j<num;j++){
        scanf("%s %s",names[j],passwd[j]);
        i=0;
        modified = false;
        while(passwd[j][i]!=0){
            if(passwd[j][i]=='1') {
                passwd[j][i] = '@';
                modified = true;
            }
            else {
                if(passwd[j][i]=='l'){passwd[j][i]='L';modified = true;}
                else if(passwd[j][i] =='O'){
                        passwd[j][i]='o';modified = true;
                }
                else if(passwd[j][i] =='0'){passwd[j][i]='%';modified = true;}
            }
            i++;
        }
        if(modified)   {changedNum++;changed[j]=true;}
    }
    if(changedNum<=0){
        if(num==1) printf("There is 1 account and no account is modified");
        else{
            printf("There are ");
            printf("%d ",num);
            printf("accounts and no account is modified");
        }
    }
    else{
        printf("%d\n",changedNum);
        for(i=0;i<num;i++){
            if(changed[i])
                printf("%s %s\n",names[i],passwd[i]);
        }
    }
}
