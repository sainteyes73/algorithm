#include <iostream>
const int MAX=1005;
int arr[MAX][MAX];
int res[MAX];
using namespace std;
int n,m,q;
int main(){
    cin>>n>>m>>q;

    for(int i=0;i<n;i++){
        int sum=0;
        for(int j=0;j<m;j++){
            int temp;
            cin>>temp;
            sum+=temp;
            if(i>0){
                arr[i][j]=arr[i-1][j]+sum;
            }else{
                arr[i][j]=sum;
            }
        }
    }
    for(int i=0;i<q;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a==0&&b==0) res[i]=arr[c][d];
        else if(a>0&&b>0){
            res[i]=arr[c][d]-arr[c][b-1]-arr[a-1][d]+arr[a-1][b-1];
        }else if(a==0) res[i]=arr[c][d]-arr[c][b-1];
        else if(b==0) res[i]=arr[c][d]-arr[a-1][d];
    }
    for(int i=0;i<q;i++){
        cout<<res[i]<<" ";
        cout<<""<<endl;
    }

    
}