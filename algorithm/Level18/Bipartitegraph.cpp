#include <iostream>
#include <algorithm>
#include <vector>
const int MAX=1005;
using namespace std;
vector <int> v[MAX];
bool visited[MAX]={0,};
int group[MAX];
int n,m;
bool flag=false;
void DFS(int x,int c){
    visited[x]=true;
    group[x]=c;
    for(int i=0;i<v[x].size();i++){
        int y=v[x][i];
        if(group[y]!=0&&group[y]==c){
            flag=true;
            return;
        }
        int c2;
        if(c==1) c2=2;
        else c2=1;
        if(visited[y]==false){
            DFS(y,c2);
        }
    }
}
int main() {
  //두개의 입력이 들어오면 이 두개를 AB집합에 따로 넣음
  //
  //Please Enter Your Code Here
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  DFS(1,1);
  if(flag==false){
      cout<<"Yes";
  }else{
      cout<<"No";
  }
  return 0;
}