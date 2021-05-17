#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

const int MAX=10500;
//위치 y x 방향 d  속력 f 무게 w
//이동 후 같은 칸에 2마리 이상 멧돼지면 무게가 큰게 먹는다
//결과는 무게합을 출력
int map[400][400];
int y[MAX];
int x[MAX];
int d[MAX];
int f[MAX];
int w[MAX];
int t,r,c,m;
int dy[5]={0,-1,1,0,0};
int dx[5]={0,0,0,-1,1};
int next_d[5]={0,2,1,4,3};
int sum=0;
int move(int cur, int dist, int max_size, int idx){
  while(cur+dist<1||cur+dist>max_size){
    d[idx]=next_d[d[idx]];
    if(cur+dist<1){
      dist+=cur-1;
      cur=1;
      dist=-dist;
    }else if(cur+dist>max_size){
      dist-=max_size-cur;
      cur=max_size;
      dist=-dist;
    }
  }
  return cur+dist;
}
int main(){
  cin>>t;
  int num=1;
  while(t!=0){

    cin>>r>>c>>m;
    for(int i=1;i<=m;i++){
      cin>>y[i]>>x[i]>>d[i]>>f[i]>>w[i];
    }
    for(int time=1;time<=c;time++){
      for(int i=1;i<=m;i++){//이동
        if(x[i]!=0&&y[i]!=0){
          y[i]=move(y[i],f[i]*dy[d[i]],r,i);
          x[i]=move(x[i],f[i]*dx[d[i]],c,i);
        }

      }
      for(int i=1;i<=m;i++){//맵에 이동 체크 및 중복제거
        if(map[y[i]][x[i]]==0) map[y[i]][x[i]]=i;
        else if(w[map[y[i]][x[i]]]>w[i]){
          w[i]=0;
          x[i]=0;
          y[i]=0;
          d[i]=0;
          f[i]=0;
        }else{
          w[map[y[i]][x[i]]]=0;
          y[map[y[i]][x[i]]]=0;
          x[map[y[i]][x[i]]]=0;
          d[map[y[i]][x[i]]]=0;
          f[map[y[i]][x[i]]]=0;
          map[y[i]][x[i]]=i;
        }
      }
      /*
      for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
          cout<<map[i][j]<<" ";
        }
        cout<<""<<endl;
      }
      */
      
      for(int i=r;i>=1;i--){
        if(map[i][time]!=0&&w[map[i][time]]>0){
          sum+=w[map[i][time]];
          w[map[i][time]]=0;
          map[i][time]=0;
          break;
        }
      }
      memset(map,0,sizeof(map));
      
    }

    cout<<"#"<<num<<" "<<sum<<endl;
    sum=0;
    t--;
    num++;
  }
}