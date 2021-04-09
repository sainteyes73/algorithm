#include<iostream>
const int MAX=10;
using namespace std;
//5 6
//1 2
//1 3
//1 4
//2 4
//4 5
//3 5
//Q1. 정점 X Y가 연결이 되어있는가?
//Q2. 정점 X와 연결되어있는 모든 정점을 출력하라
bool isConnected(int x, int y, int myGraph[][MAX]){    
    return myGraph[x][y]==1 ? true: false;
}
void getAdj(int myGraph[MAX][MAX], int n,int x){
    //adjacent 인접해있는
    //myGraoh에서 x와 연결되어 있는 모든 정점 출력
    for(int i=1;i<=n;i++){
        if(myGraph[x][i]==1) cout<<i;
    }
}
int main(){
    int n,m;
    int myGraph[MAX][MAX]={0,};

    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        myGraph[a][b]=1;
        myGraph[b][a]=1;
    }
    cout<<(int)isConnected(1,2,myGraph);
    cout<<(int)isConnected(1,5,myGraph);
    cout<<(int)isConnected(3,5,myGraph);

    getAdj(myGraph,n,2);
    getAdj(myGraph,n,3);    
    return 0;
}