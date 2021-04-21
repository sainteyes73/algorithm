#include <iostream>
#include <vector>
using namespace std;
const int MAX=100;
int t,r,c,m;
int dx[5]={0,0,0,-1,1};
int dy[5]={0,-1,1,0,0};
int arr[MAX][MAX];
int visit[MAX][MAX];
//1~r 1~c  r->y c->x
struct animal{
  int y,x;
  int d;//방향
  int f;//속력
  int w;//무게
  void move(){
    if(d<3){//상 하
        visit[y][x]=0;
        f%=2*r-2;
        while(y+dy[d]*f<1||y+dy[d]*f>r){
            if(y+dy[d]*f<1){
                t-=y-1;
                y=1;
                d=2;
            }else if(y+dy[d]*f>r){
                t-=r-y;
                y=r;
                d=1;
            }
        }
        y+=dy[d]*f;
        if(visit[y][x]<w) visit[y][x]=w;
        else w=0;

    }else{
        visit[y][x]=0;
        f%=2*r-2;
        while(x+dx[d]*f<1||y+dx[d]*f>c){
        
            if(x+dx[d]*f<1){
                t-=x-1;
                x=1;
                d=4;
            }else if(x+dx[d]*f>c){
                t-=c-x;
                x=c;
                d=3;
            }
        }
        x+=dx[d]*f;
        if(visit[y][x]<w) visit[y][x]=w;
        else w=0;
    }

  }
};
animal make_animal(int y, int x, int d,int f, int w){
    animal pig;
    pig.y=y;
    pig.x=x;
    pig.d=d;
    pig.f=f;
    pig.w=w;
    return pig;
}
int main() {

  //Please Enter Your Code Here
  int t;
  cin>>t;
  vector<animal> v;
  
      cin>>r>>c>>m;
      for(int i=0;i<m;i++){
          int y,x,d,f,w;    
          cin>>y>>x>>d>>f>>w;
          v.push_back(make_animal(y,x,d,f,w));
                        cout<<"asd"<<endl;
      }

      for(int i=1;i<=c;i++){
          for(int i=0;i<v.size();i++){//움직임
              v[i].move();

          }
          bool flag=false;
          for(int j=r;j>=1;j--){
              if(flag==false){
                if(visit[j][i]>0){
                    for(int k=0;k<c;k++){
                        if(v[k].w==visit[j][i]){
                            v[k].w=0;
                            visit[j][i]=0;
                            flag=true;
                        }
                    }
                }
              }else break;
          }
      }
      int sum=0;
      for(int i=0;i<v.size();i++){
          sum+=v[i].w;
      }
      cout<<sum<<endl;
      
  
  return 0;
}