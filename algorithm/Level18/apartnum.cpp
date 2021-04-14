#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int MAX=30;
int arr[MAX][MAX]={0,};
int n;
vector<int> v;
int getGroup(int y,int x){
    int dy[4]={1,-1,0,0};
    int dx[4]={0,0,-1,1};
    int cnt=0;
    arr[y][x]=0;
    cnt++;
    for(int i=0;i<4;i++){
        int yy=y+dy[i];
        int xx=x+dx[i];
        if(arr[yy][xx]){
            cnt+=getGroup(yy,xx);
        }
    }
    return cnt;
}
void dfs(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(arr[i][j]==1){
                v.push_back(getGroup(i,j));
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    dfs();
    sort(v.begin(),v.end());
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
}