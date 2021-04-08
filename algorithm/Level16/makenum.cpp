//table을 어떻게 정의했는지
//점화식을 어떻게 세웠는지
//T(i)는 1~m까지의 숫자를 이용해서 숫자 i 를 만드는 경우의 수
//T(i)=T(i-1)+T(i-2)+...+T(i-N)
#include<iostream>
using namespace std;
const int MAX=100;

int Table[MAX];
int n,m;
int main(){
    cin>>n>>m;

    //M=4
    //Table[1]=1
    //Table[2]=2 -> Table[1] +1 
    //Table[3]=4 -> 1~4를 이용해서 3을 만드는 경우의수ㅅ Table[2]+Table[1]+1
    //Table[4]=? -> Table[3]+Table[2]+Table[1]+1
    //->1~M까지는 위와 같이 M이후부터는 위를 합쳐서
    Table[1]=1;
    int sum=0;
    for(int i=2;i<=m;i++){
        sum+=Table[i-1];
        Table[i]=sum+1;
    }
    for(int i=m+1;i<=n;i++){
        for(int j=i-m;j<=i-1;j++){
            Table[i]+=Table[j];
        }
    }
    cout<<Table[n]<<endl;
    return 0;
}