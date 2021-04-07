#include<iostream>
const int MAX=100;
using namespace std;
int n;
int arr[MAX];
bool print=false;
bool isPossible(int x, int length){
    for(int i=0;i<length;i++){
        if(arr[x-i]!=arr[x-i-length]){
            return true;
        }
        
    }
    return false;
}
void getResult(int x){
    if(print==true) return;
    if(x==n){
        for(int i=0;i<n;i++){
            cout<<arr[i];
        }
        cout<<""<<endl; 
        print=true;

    }else{
        for(int i=1;i<=3;i++){
            arr[x]=i;
            bool flag=false;
            for(int j=1;j<=(x+1)/2;j++){
                if(!isPossible(x,j)){
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                getResult(x+1);
            }
        }

    }
}
int main(){
    cin>>n;
    getResult(0);
}