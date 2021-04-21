#include<iostream>
#include<vector>
#include<queue>

using namespace std;

const int MAX=1050;
int n,m;
int map[MAX][MAX];
int sum[MAX][MAX];
int visited[MAX][MAX];

struct p{
    int x;
    int y;

};
p make_p(int y,int x){
    p temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
queue<p> q;
void dfs(){//시작 map[n-1][0] 끝 map[0][m-1]
    
    q.push(make_p(n-1,0));
    visited[n-1][0]=true;
    while(!q.empty()){
        p current=q.front();
        q.pop();

    }
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    dfs();
}