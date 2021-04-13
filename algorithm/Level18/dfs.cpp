#include <iostream>
#include <vector>
using namespace std;
const int MAX=100;
int n,m;
vector <int> myGraph[MAX];
bool visited[MAX];
void DFS(int x){
  visited[x]=true;
  cout<<x;
  for(int i=0;i<myGraph[x].size();i++){
    int y=myGraph[x][i];
    if(visited[y]==false){
      DFS(y);
    }
  }
}
int main() {

  //Please Enter Your Code Here
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a, b;
    cin>>a>>b;
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  DFS(1);
  cout<<""<<endl;
  return 0;
}