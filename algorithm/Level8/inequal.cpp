#include<iostream>
using namespace std;
const int MAX = 100;
char arr[MAX];
int maxresult[MAX];
int minresult[MAX];
bool maxFlag[MAX]={0,};
bool minFlag[MAX]={0,};
bool printMax=false;
bool printMin=false;
int n;
void getMax(int x){
    if(x>n){
        if(printMax==false){
            for(int i=0;i<x;i++){
                cout<<maxresult[i];
            }
            cout<<""<<endl;
        }
        printMax=true;
        
    }else{
        for(int i=9;i>=0;i--){

            if(maxFlag[i]==false){
                maxresult[x]=i;
                bool flag=false;
                if(x==0){
                    flag=true;
                } 
                else{
                    if(arr[x-1]=='>'){
                        if(maxresult[x-1]>maxresult[x]){
                            flag=true;
                        }
                    }else if(arr[x-1]=='<'){
                        if(maxresult[x-1]<maxresult[x]){
                            flag=true;
                        }
                    }
                }
                if(flag==true){
                    maxFlag[i]=true;
                    getMax(x+1);
                    maxFlag[i]=false;
                }    
            }
        }
    }
}
void getMin(int x){
    if(x>n){
        if(printMin==false){
            for(int i=0;i<x;i++){
                cout<<minresult[i];
            }
            cout<<""<<endl;
        }
        printMin=true;
    }else{
        for(int i=0;i<=9;i++){
            if(minFlag[i]==false){
                minresult[x]=i;
                bool flag=false;
                if(x==0){
                    flag=true;
                } 
                else{
                    if(arr[x-1]=='>'){
                        if(minresult[x-1]>minresult[x]){
                            flag=true;
                        }
                    }else if(arr[x-1]=='<'){
                        if(minresult[x-1]<minresult[x]){
                            flag=true;
                        }
                    }
                }
                if(flag==true){
                    minFlag[i]=true;
                    getMin(x+1);
                    minFlag[i]=false;
                }    
            }
        }
    }
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        scanf(" %c",&arr[i]);
    }
    getMax(0);
    getMin(0);
}
