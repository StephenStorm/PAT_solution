//2019.3.23  start time:23.03  endtime 2019.3.24  21:34
#include<iostream>
#include<string.h>
#include<algorithm>
#include<stack>
#include<vector>
using namespace std;
void del(vector<int>,int);
int main(){
    stack<int> st;
    char str[13];
    vector<int> order;
    int num,amount = 0;
    int mid,tmp,key,i;
    char tt[8];
    vector<int>::iterator it;
    cin>>num;
    getchar();
    while(num--){//num´ÎÊäÈë
        gets(str);
        if(strcmp(str,"Pop")==0){
            if(amount>0){
                tmp = st.top();
                st.pop();
                order.erase(lower_bound(order.begin(),order.end(),tmp));
                cout<<tmp<<endl;
                amount--;
            }
            else cout<<"Invalid"<<endl;
        }
        else if(strcmp(str,"PeekMedian")==0){
                if(amount>0){
                    mid = (amount-1)/2;
                    cout<<order[mid]<<endl;
                }
                else cout<<"Invalid"<<endl;
            }
            else{//push Ñ¹Õ»²Ù×÷
                i=0;
                while(str[i+5]!=0){tt[i]=str[i+5];i++;}
                tt[i] = 0;
                sscanf(tt,"%d",&key);
                st.push(key);
                amount++;
                it = upper_bound(order.begin(),order.end(),key);
                order.insert(it,key);
            }
    }
}
