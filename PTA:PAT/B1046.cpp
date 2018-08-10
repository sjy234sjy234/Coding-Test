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

int N,CountJ,CountY;

void Input(){
	scanf("%d",&N);
}

void Process(){
	int j_han,j_hua,y_han,y_hua;
	CountJ=CountY=0;
	for(int i=0;i<N;i++){
		scanf("%d%d%d%d",&j_han,&j_hua,&y_han,&y_hua);
		if(j_hua==j_han+y_han&&y_hua!=j_han+y_han)
			CountY++;
		if(j_hua!=j_han+y_han&&y_hua==j_han+y_han)
			CountJ++;
	}
}

void Display(){
	printf("%d %d\n",CountJ,CountY);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}