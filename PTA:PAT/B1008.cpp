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

int N,M,A[100];

void Input(){
	int i;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++)
		scanf("%d",&A[i]);
	M%=N;
}

void Reverse(int low,int high){
	int l=(low+high+1)/2,temp;
	for(int i=low;i<l;i++){
		temp=A[i];
		A[i]=A[low+high-i];
		A[low+high-i]=temp;
	}
}

void Process(){
	Reverse(0,N-1);
	Reverse(0,M-1);
	Reverse(M,N-1);
}

void Display(){
	printf("%d",A[0]);
	for(int i=1;i<N;i++)
		printf(" %d",A[i]);
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