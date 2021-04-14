#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
const int MAX=1005;
using namespace std;
int n,m;
int map[MAX][MAX];
int sum[MAX][MAX];
int visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
bool flag=false;
struct p{
    int x;
    int y;
};
queue<p> q;

p make_p(int y, int x){
    p temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
void find(){//시작 arr[m-1][0] 끝 arr[0][n-1] y x
    q.push(make_p(n-1,0));
    visited[n-1][0]=true;
    while(!q.empty()){
        p current=q.front();
        q.pop();
        int curX=current.x;
        int curY=current.y;
        for(int k=0;k<4;k++){
            int xx=curX+dx[k];
            int yy=curY+dy[k];
            if(0<=xx&&xx<m&&0<=yy&&yy<n&&map[yy][xx]==0&&!visited[yy][xx]){
                sum[yy][xx]=sum[curY][curX]+1;

                visited[yy][xx]=true;
                q.push(make_p(yy,xx));
            }
        }
    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }
    find();
    cout<<sum[0][m-1];
}