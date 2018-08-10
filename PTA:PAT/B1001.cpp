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

int N,Step;

void Input(){
	scanf("%d",&N);
}

void Process(){
	Step=0;
	while(N!=1){
		if(N%2)
			N=(3*N+1)/2;
		else
			N/=2;
		Step++;
	}
}

void Display(){
	printf("%d\n",Step);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}