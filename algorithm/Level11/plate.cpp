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
    int capacity;
    int len;
    char data[MAX];

    void create(){
        capacity=MAX;
        len=0;
    }
    void push(int x){
        if(len>=capacity)    return;
        data[len++]=x;
    }
    char pop(){
        if(len<=0) return;
        int temp=data[len];
        data[len]=0;
        len--;
        return temp;
    }
    char top(){
        if(len<=0) return;
        return data[len];
    }
};
int main(){
    bool flag;
    cin>>arr;
    Stack s;
    s.create();
    int arr_pointer;
    char alpha='a';
    int alphapoint=0;
    while(1){
        int i=0;//arr를 가리키는 포인터
        char current=arr[i];//pop해야할값
        char stacktop=s.top();//stack의 top
        if(current==stacktop){
            save[i]=s.pop();
            i++;
        }else{
            if(alpha=='a'+strlen(arr)){
                break;
            }else{
                s.push(alpha++);
                alphapoint++;
            }
        }
        if(i==strlen(arr)){
            if(arr==save) break;
        }
    }
}