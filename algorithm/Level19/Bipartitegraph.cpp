#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAX=1005;
bool visited[MAX]={0,};
int group[MAX]={0,};
int n,m;
vector<int> v[MAX];
queue<int> q;
bool flag=false;
void bfs(int c){
    q.push(1);
    visited[1]=true;
    group[1]=c;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0;i<v[current].size();i++){
            int y=v[current][i];
            if(group[y]!=0&&group[y]==group[current]){
               flag=true;
               return; 
            }
            int c2;
            if(group[current]==1){
                c2=2;
            }else{
                c2=1;
            } 
            if(visited[y]==false){
                q.push(y);
                group[y]=c2;
                visited[y]=true;
            }

        }
    }
    
}
int main(){
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    if(flag){
        cout<<"No";
    }else cout<<"Yes";
}