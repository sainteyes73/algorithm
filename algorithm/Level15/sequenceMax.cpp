#include <iostream>
using namespace std;
const int MAX =100;
int n;
int data[MAX];

int getSubMax(int start, int end){
    //data의 start부터 end까지 연속부분 최대합을 구해주는 함수

    if(start>=end) return data[start];
    int mid=(start+end)/2;
    int left=getSubMax(start,mid);//left
    int right=getSubMax(mid+1,end);//right;

    int leftSum=0;
    int leftMax=-987987987;
    for(int i=mid;i>=start;i--){
        leftSum=leftSum+data[i];
        if(leftMax<leftSum)
            leftMax=leftSum;
    }
    int rightSum=0;
    int rightMax=-987987987;
    for(int i=mid+1;i<=end;i++){
        rightSum=rightSum+data[i];
        if(rightMax<rightSum)
            rightMax=rightSum;
    }
    int myMax=leftMax+rightMax;
    if(left>=right&&left>=myMax) return left;
    else if(right>=left&&right>=myMax) return right;
    else return myMax;
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>data[i];
    } 
    cout<<getSubMax(0,n-1);
    return 0;
}