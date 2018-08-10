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

int N,M,A[100000];

void Input(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	sort(A,A+N);
}

void Process(){
	int i=0,j=N-1;
	while(i<j){
		if(A[i]+A[j]==M){
			printf("%d %d\n",A[i],A[j]);
			return;
		}
		else if(A[i]+A[j]>M)
			j--;
		else
			i++;
	}
	printf("No Solution\n");
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