//2019.3.31
#include<vector>
#include<algorithm>
#include<stdio.h>
#include<utility>
using namespace std;
struct graduate{
    int apply[5];
    int ge;
    int gi;
    float fgrade;
    int id;
};
bool cmp(graduate g1,graduate g2){
    return g1.fgrade == g2.fgrade?g1.ge>g2.ge:g1.fgrade>g2.fgrade;
}
int main(){
    int n,m,k;
    scanf("%d %d %d",&n,&m,&k);
    vector<graduate> gra(n);
    vector<int> quota(m);
    vector<vector<pair<int,int> > > school(m);
    int i,j,index,last;
    pair<int,int> tmp;
    for(i=0;i<m;i++){
        scanf("%d",&quota[i]);
    }
    for(i=0;i<n;i++){
        scanf("%d %d",&gra[i].ge,&gra[i].gi);
        gra[i].fgrade = (gra[i].ge+gra[i].gi)/2.0;
        for(j=0;j<k;j++){
            scanf("%d",&gra[i].apply[j]);
        }
        gra[i].id = i;
    }
    sort(gra.begin(),gra.end(),cmp);
    for(i=0;i<n;i++){
        for(j=0;j<k;j++){
            index = gra[i].apply[j];
            if(school[index].size()<quota[index]){
                school[index].push_back(make_pair(gra[i].id,i));
                break;
            }
            if(!school[index].empty()){
                tmp = *(school[index].end()-1);
                last = tmp.second;
                if((gra[i].fgrade==gra[last].fgrade) && (gra[i].ge == gra[last].ge)){
                    school[index].push_back(make_pair(gra[i].id,i));
                    break;
                }
            }
        }
    }
    for(i=0;i<m;i++){
        if(!school[i].empty()){
            sort(school[i].begin(),school[i].end());
            printf("%d",school[i][0].first);
            for(j=1;j<school[i].size();j++)
                printf(" %d",school[i][j].first);
        }
        printf("\n");
    }
}
