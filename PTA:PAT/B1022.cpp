#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int A,B,D,S;
stack<int> Stk;

void Input(){
	scanf("%d%d%d",&A,&B,&D);
	S=A+B;
	while(S>0){
		Stk.push(S%D);
		S/=D;
	}
	if(Stk.empty())
		Stk.push(0);
}

void Process(){

}

void Display(){
	while(!Stk.empty()){
		printf("%d",Stk.top());
		Stk.pop();
	}
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}