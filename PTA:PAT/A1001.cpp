#include<iostream>
#include<algorithm>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int A,B,Ans;
stack<int> S;

void Input(){
	scanf("%d%d",&A,&B);
	Ans=A+B;
}

void Process(){
	if(Ans<0)
		printf("-");
	Ans=abs(Ans);
	while(Ans>0){
		S.push(Ans%1000);
		Ans/=1000;
	}
}

void Display(){  //经验总结,栈和队列空时访问会出现段错误;
	if(S.empty())  
		printf("0");
	else{
	printf("%d",S.top());
	S.pop();
	while(!S.empty()){
		printf(",%03d",S.top());  //注意要输出整3位;
		S.pop();
	}
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