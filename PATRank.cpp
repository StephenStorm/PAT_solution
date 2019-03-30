//2019.3.30 start time: 11.12 ACTime 12:12
//排序加排名赋值
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
struct testee{
    string id;
    int finalRank;
    int locRank;
    int locN0;
    int score;
};
bool cmp(testee t1,testee t2){
    return t1.score==t2.score?(t1.id<t2.id):(t1.score>t2.score);
}
int main(){
    int num1,num2;
    testee input;
    cin>>num1;
    vector<testee> tests;
    int i,j,k,amount=0;
    for(i=0;i<num1;i++){
        cin>>num2;
        amount+=num2;
        for(j=0;j<num2;j++){
            cin>>input.id>>input.score;
            input.locN0 = i+1;
            tests.push_back(input);
        }
        sort(tests.end()-num2,tests.end(),cmp);
        j = amount - num2;
        tests[j].locRank = 1;
        for(k=j+1;k<amount;k++){
            if(tests[k].score == tests[k-1].score){
                tests[k].locRank = tests[k-1].locRank;
            }
            else{
                tests[k].locRank = k-j+1;
            }
        }
    }
    sort(tests.begin(),tests.end(),cmp);
    tests[0].finalRank=1;
    for(i=1;i<amount;i++){
        if(tests[i].score == tests[i-1].score)
            tests[i].finalRank = tests[i-1].finalRank;
        else
            tests[i].finalRank = i+1;
    }
    cout<<amount<<endl;
    for(i=0;i<amount;i++){
        cout<<tests[i].id<<" "<<tests[i].finalRank<<" "<<tests[i].locN0<<" "<<tests[i].locRank<<endl;
    }
}
