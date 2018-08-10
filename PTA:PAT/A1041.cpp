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

int N,A[100000],Hash[10001];

void Input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		Hash[A[i]]++;
	}
}

void Process(){
	int i;
	for(i=0;i<N;i++){
		if(Hash[A[i]]==1){
			printf("%d\n",A[i]);
			break;
		}
	}
	if(i==N)
		printf("None\n");
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