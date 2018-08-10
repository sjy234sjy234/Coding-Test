#include<iostream>  //简单的哈希应用;
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

int N,K,Count[101];

void Input(){
	int i,score;
	for(i=0;i<101;i++)
		Count[i]=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&score);
		Count[score]++;
	}
	scanf("%d",&K);
	scanf("%d",&score);
	printf("%d",Count[score]);
	for(i=1;i<K;i++){
		scanf("%d",&score);
		printf(" %d",Count[score]);
	}
	printf("\n");
}

void Process(){
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