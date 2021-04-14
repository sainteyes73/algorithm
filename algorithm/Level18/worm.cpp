#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
const int MAX=105;
int n,m;
vector<int> v[MAX];
int result=0;
bool visited[MAX]={0,};
void dfs(int x){
    visited[x]=true;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(!visited[y]) dfs(y);
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
    dfs(1);
    cout<<result;
}