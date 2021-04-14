#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>


using namespace std;
const int MAX=30;
int n;
int arr[MAX][MAX];
vector <int> result;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};

struct p{
    int x;
    int y;
};
queue<p> q;
p make_p(int y,int x){
    p temp;
    temp.x=x;
    temp.y=y;
    return temp;
}
int getResult(int y, int x){
    int cnt=0;
    q.push(make_p(y,x));
    arr[y][x]=0;
    cnt++;
    while(!q.empty()){
        p current=q.front();
        q.pop();
        int curX=current.x;
        int curY=current.y;

        for(int i=0;i<4;i++){
            int xx=curX+dx[i];
            int yy=curY+dy[i];
            if(0<=xx&&xx<n&&0<=yy&&yy<n&&arr[yy][xx]==1){
                q.push(make_p(yy,xx));
                arr[yy][xx]=0;
                cnt++;
                cout<<yy<<" "<<xx<<endl;
            }
        }
    }
    return cnt;
}
void find(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(arr[i][j]==1){
                result.push_back(getResult(i,j));
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%1d",&arr[i][j]);
        }
    }
    find();
    sort(result.begin(),result.end());
    cout<<result.size()<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<endl;
    }
}