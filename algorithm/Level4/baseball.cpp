#include <iostream>
using namespace std;
bool flag[10]={0,};
int n;
int arr[10];
int confirm[100][3];

int result=0;
void getValue(int x){
  if(x==3){
    bool judge=false;
    for(int i=0;i<n;i++){
      int hundred,ten,one;
      hundred=confirm[i][0]/100;
      ten=(confirm[i][0]/10 )%10;
      one=confirm[i][0]%10;
      int strike=0;
      int ball=0;
      if(hundred==arr[0]) strike++;
      if(ten==arr[1]) strike++;
      if(one==arr[2]) strike++;
      if(hundred==arr[1]||hundred==arr[2]) ball++;
      if(ten==arr[0]||ten==arr[2]) ball++;
      if(one==arr[0]||one==arr[1]) ball++;
      if(strike!=confirm[i][1]||ball!=confirm[i][2])
        judge=true;
    }
    if(judge==false) result++;
  }else{
    for(int i=1;i<=9;i++){
      if(flag[i]==false){
        arr[x]=i;
        flag[i]=true;
        getValue(x+1);
        arr[x]=0;
        flag[i]=false;
      }
    }
  }
}
int main() {

  cin>>n;
  for(int i=0;i<n;i++){
    cin>>confirm[i][0];//숫자
    cin>>confirm[i][1];//strike
    cin>>confirm[i][2];//ball
  }
  
  //Please Enter Your Code Here
  //123~987을 확인해본다.
  getValue(0);
  cout<<result;
}