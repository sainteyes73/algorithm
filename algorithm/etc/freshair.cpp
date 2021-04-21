#include <iostream>
#include <cstdlib>
using namespace std;
const int MAX=105;
int r,c,s,k;
int arr[MAX][MAX];
int res[MAX][MAX];
int save[MAX];
void spread(int y,int x){
  int v= (2*k*k)+(2*k)+1;
  int count=0;
  int bad=arr[y][x]/v;
  for(int i=y-k;i<=y+k;i++){
      if(i<1||i>r) continue;
      for(int j=x-k;j<=x+k;j++){
          if(j<1||j>c) continue;
          if(y==i&&x==j) continue;
          if(arr[i][j]==-1) continue;
          int dist=abs(i-y)+abs(j-x);
          if(dist<=1&&dist<=k){
              count++;
              res[i][j]+=bad;
          } 
      }
  }
  res[y][x]-=(bad*count);
}
void airfresh(int y){//1 ~ 5, 1~7, arr[3][7]==-1 y=3 r=5 c=7
  int d=y+1;
  int temp=arr[y][1];
  for(int i=1;i<c-1;i++) arr[y][i]=arr[y][i+1];
  for(int i=y-1;i>1;i--) arr[i][c]=arr[i-1][c];
  for(int i=c;i>1;i--) arr[1][i]=arr[1][i-1];
  for(int i=1;i<y;i++) arr[i][1]=arr[i+1][1];
  arr[y-1][1]=temp;
  arr[y][c-1]=0;
  temp=arr[d][1];
  for(int i=1;i<c-1;i++) arr[d][i]=arr[d][i+1];
  for(int i=d+1;i<r;i++) arr[i][c]=arr[i+1][c];
  for(int i=c;i>1;i--) arr[r][i]=arr[r][i-1];
  for(int i=r;i>d;i--) arr[i][1]=arr[i-1][1];
  arr[d+1][1]=temp;
  arr[d][c-1]=0;

}
/*
1
6 9 4 2
15 10 0 0 3 0 18 0 14 
20 2 0 0 0 4 0 9 17 
0 0 0 0 0 0 14 12 0 
0 0 0 0 0 12 0 0 -1 
0 0 0 0 0 7 0 0 -1 
0 0 3 17 5 0 0 15 0
*/
int main() {
  int num=0;
  //Please Enter Your Code Here
  int t;
  cin>>t;
  //r c 타
  //
  while(t!=0){
    cin>>r>>c>>s>>k;
    arr[MAX][MAX]={0};
    res[MAX][MAX]={0};

    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        cin>>arr[i][j];
      }
    }
    int v= (2*k*k)+(2*k)+1;
    for(int time=0;time<s;time++){
      for(int i=1;i<=r;i++){//확산
        for(int j=1;j<=c;j++){
          if(arr[i][j]>=v){
            spread(i,j);
          }     
        }
      }

      for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
          arr[i][j]+=res[i][j];
          res[i][j]=0;
        }
      }
            for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
          cout<<arr[i][j]<<" ";
        }
        cout<<""<<endl;
      }
      for(int i=1;i<=r;i++){
        if(arr[i][c]==-1){
          airfresh(i);
          break;
        }
     }
    }
    int sum=0;
    for(int i=1;i<=r;i++){
      for(int j=1;j<=c;j++){
        if(arr[i][j]==-1) continue;
        sum+=arr[i][j];
      }
    }
    save[num]=sum;
    num++;
    t--;
  }
  for(int i=0;i<num;i++){
    cout<<"#"<<i+1<<" "<<save[i]<<endl;
  }
  return 0;
}