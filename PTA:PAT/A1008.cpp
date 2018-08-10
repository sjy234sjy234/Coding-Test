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
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace std;

int N;
int A[10001],T;

void Input(){
	int i;
	scanf("%d",&N);
	A[0]=0;
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);
}

void Process(){
	int i,temp;
	T=0;
	for(i=1;i<=N;i++){
		temp=A[i]-A[i-1];
		if(temp>0)
			T+=6*temp;
		else
			T-=4*temp;
	}
	T+=5*N;
}

void Display(){
	printf("%d\n",T);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
