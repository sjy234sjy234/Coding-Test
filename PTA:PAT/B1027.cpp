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

int N,H,R;
char S;

void Input(){
	scanf("%d%c%c",&N,&S,&S);
	H=sqrt((double)(N+1)/2);
	R=N+1-2*H*H;
}

void Process(){
	int i,j;
	for(i=H;i>=1;i--){  //充分利用对称性,代码逻辑变得非常简单;
		for(j=0;j<H-i;j++)
			printf(" ");
		for(;j<H+i-1;j++)
			printf("%c",S);
		printf("\n");
	}
	for(i=2;i<=H;i++){
		for(j=0;j<H-i;j++)
			printf(" ");
		for(;j<H+i-1;j++)
			printf("%c",S);
		printf("\n");
	}
}

void Display(){
	printf("%d\n",R);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}