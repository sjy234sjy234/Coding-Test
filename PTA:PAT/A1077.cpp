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

struct phrase{
	char data[260];
	int i_pos;
}A[100];

int N;
stack<char> S;

void Input(){
	int i;
	scanf("%d",&N);
	getchar();
	for(i=0;i<N;i++){
		gets(A[i].data);
		A[i].i_pos=strlen(A[i].data)-1;
	}
}

void Process(){
	int i;
	bool flag=true;
	while(flag){
		for(i=1;i<N;i++){
			if(A[i].i_pos<0||A[i-1].i_pos<0){
				flag=false;
				break;
			}
			if(A[i].data[A[i].i_pos]!=A[i-1].data[A[i-1].i_pos]){
				flag=false;
				break;
			}
			A[i-1].i_pos--;
		}
		if(flag)
			S.push(A[N-1].data[A[N-1].i_pos--]);
	}
}

void Display(){
	if(S.empty())
		printf("nai\n");
	else{
		while(!S.empty()){
			printf("%c",S.top());
			S.pop();
		}
		printf("\n");
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}