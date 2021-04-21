#include<iostream>
#include<queue>
#include<vector>

using namespace std;
const int MAX=100001;
vector<int> v;
queue<int> q;

int n,k;
int cnt=0;
bool visited[MAX];
int main(){
    cin>>n>>k;
    q.push(k);
    visited[k]=true;
    cnt++;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        int first=current*2;
        int second=current/3;
        if(first<=n&&!visited[first]){
            q.push(first);
            visited[first]=true;
            cnt++;
        }
        if(second>0&&!visited[second]){
            q.push(second);
            visited[second]=true;
            cnt++;
        }
    }
    cout<<n-cnt;
}
