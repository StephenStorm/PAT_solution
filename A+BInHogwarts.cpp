//2019.3.27
//��ͬ�����������
//����˵�����Ŀ�Ĵ��������Һܳ�ʱ�䣬�����ջ�޴��������ջ�����������sccanf�����ܹ�ʡ�ºܶ��ʱ��
//�����������ʹ��ѭ�����ָ�������ַ����������˽⵽sscanf���÷��󣬷��ֻ����ǳ
#include<iostream>
using namespace std;
int main(){
    char str1[20],str2[20];
    scanf("%s %s",str1,str2);
    int first[3],second[3];
    sscanf(str1,"%d.%d.%d",&first[0],&first[1],&first[2]);
    sscanf(str2,"%d.%d.%d",&second[0],&second[1],&second[2]);
    int tmp,res[3],carry;
    tmp = first[2]+second[2];
    carry = tmp/29;
    res[2] = tmp%29;
    tmp = carry+first[1]+second[1];
    carry = tmp / 17;
    res[1] = tmp%17;
    res[0] = first[0]+second[0]+carry;
    printf("%d.%d.%d",res[0],res[1],res[2]);
}
