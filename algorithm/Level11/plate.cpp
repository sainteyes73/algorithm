/*
문제

접시 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때,
 b a c d 순으로 꺼내기 위해서는 push, push, pop, pop, push, pop, push, pop을 하면 된다. 
 세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오.
  만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다.

 

입력

첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다. 입력되는 알파벳의 길이는 최대 26 자리이다.  

출력

접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다.  
*/
#include<iostream>
#include<string.h>

using namespace std;
const int MAX=30;
char arr[MAX];
char save[MAX];//pop을 저장
struct Stack{
    int capacity=30;
    int len=0;
    char data[MAX];

    void push(char x){
        if(len<capacity){
            data[len]=x;
            len++;
        }
    }
    void pop(){
        if(len>0){
            data[len]=0;
            len--;
        }
    }
    char top(){
        if(len>0){
            char item;
            item=data[len-1];
            return item;   
        }else{
            return -1;
        }
    }
    void current(){
        for(int i=0;i<=len;i++){
            cout<<data[i];
        }
    }
};

int main(){
    bool flag;
    cin>>arr;
    Stack s;
    int result[100];
    int arr_pointer;
    char alpha='a';
    int alphapoint=0;
    int result_point=0;
    int i=0;
    while(1){
        char current=arr[i];//pop해야할값
        char stacktop=s.top();//stack의 top
        if(current==stacktop){
            s.pop();
            i++;
            result[result_point++]=1;
            if(i==strlen(arr)){
                flag=true;
                break;
            }
        }else{
            if(alpha=='a'+strlen(arr)){
                flag=false;
                break;
            }else{
                s.push(alpha++);
                alphapoint++;
                result[result_point++]=0;
            }
        }
    }
    if(flag==true){
        for(int i=0;i<result_point;i++){
            if(result[i]==1){
                cout<<"pop"<<endl;
            }else{
                cout<<"push"<<endl;
            }
        }
    }else{
        cout<<"impossible"<<endl;
    }
}