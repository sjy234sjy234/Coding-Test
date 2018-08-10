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

int N,H,W;
char C;

void Input(){
	scanf("%d%c%c",&N,&C,&C);
	W=N;
	H=(N+1)/2;
}

void Process(){
	int i,j;
	for(i=1;i<=H;i++){
		if(i==1||i==H)
			for(j=1;j<=W;j++)
				printf("%c",C);
		else{
			printf("%c",C);
			for(j=2;j<W;j++)
				printf(" ");
			printf("%c",C);
		}
		printf("\n");
	}
}

void Display(){

}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}