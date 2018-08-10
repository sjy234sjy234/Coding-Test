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

int N,B,S,G;

void Input(){
	scanf("%d",&N);
	B=N/100;
	N%=100;
	S=N/10;
	N%=10;
	G=N;
}

void Process(){

}

void Display(){
	while(B-->0)
		printf("B");
	while(S-->0)
		printf("S");
	for(int i=1;i<=G;i++)
		printf("%d",i);
	printf("\n");
}

int main(){
	while(true){
	Input();
	Process();
	Display();
	}
	return 0;
}