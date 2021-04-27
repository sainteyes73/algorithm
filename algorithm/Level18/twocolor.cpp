#include<iostream>
#include<vector>
using namespace std;
const int MAX=100050;

bool visited[MAX];
int color[MAX];
vector <int> v[MAX];
int n,m;
bool flag;
void dfs(int x,int c){
    visited[x]=true;
    color[x]=c;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        int c2;
        if(c==1) c2=2;
        else c2=1;
        if(color[y]&&color[x]==color[y]){
            flag=true;
            break;
        }
        if(visited[y]==false&&!color[y]){ 
            dfs(y,c2);
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
    dfs(0,1);
    if(flag==true) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}