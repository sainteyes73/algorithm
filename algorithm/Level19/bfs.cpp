#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
const int MAX=100;
vector<int> myGraph[MAX];
/*
9 12
1 2
1 3
2 3
2 4
2 6
3 7
4 5
4 7
4 8
5 6
7 8
8 9
*/
void BFS(){
  //1. 시작점을 큐에다가 삽입
  //2. 시작점 색칠
  //3. 큐에서 하나를 뺀다. ->현재위치
  //4. 인접한 모든 정점에게 방문했는지 물어보고
  // 방문을 하지 않았다면, 색칠하고 큐에 삽입
  //5. 모두 완료했다면 다시 3.으로 돌아간다.
  bool check[MAX]={0,};
  queue <int> q;
  /*
  q.push(x);
  q.pop();
  q.front();->원소반환
  q.empty()
  */
  q.push(1);
  check[1]=true;
  while(!q.empty()){
    int current=q.front();
    cout<<current<<" ";
    q.pop();
    for(int i=0;i<myGraph[current].size();i++){
      int next=myGraph[current][i];
      if(check[next]==false){
        q.push(next);
        check[next]=true;
      }
    }

  }

  
}
int main() {

  //Please Enter Your Code Here
  cin>>n>>m;
  for(int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    myGraph[a].push_back(b);
    myGraph[b].push_back(a);
  }
  BFS();
  return 0;
}