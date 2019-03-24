//2.19.3.22 start: 21.20 -22.30//起初报错  后期自己AC   浪费时间
//#include<stdio.n>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string fname="Absent",mname="Absent",name;
    char gender;
    string ID,fid,mid;
    int fgrade=-1,mgrade=101,grade;
    int num;
    cin>>num;
    for(int i=0;i<num;i++){
        cin>>name>>gender>>ID>>grade;
        if(gender=='F'&&grade>fgrade) {
            fname = name;
            fid = ID;
            fgrade = grade;
            continue;
        }
        if(gender=='M'&&grade<mgrade){
            mname = name;
            mid = ID;
            mgrade = grade;
        }
    }
    int i=0;
    if(fname!="Absent"){
        cout<<fname<<" "<<fid<<endl;
        i++;
    }
    else cout<<"Absent"<<endl;
    if(mname!="Absent"){
        cout<<mname<<" "<<mid<<endl;
        i++;
    }
    else cout<<"Absent"<<endl;
    if(i==2) cout<<fgrade-mgrade;
    else cout<<"NA";

}
