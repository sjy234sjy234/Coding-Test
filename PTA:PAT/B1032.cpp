#include<iostream>  //要非常注意下标是从0开始还是从1开始;
#include<algorithm>  //考试的时候无论什么情况都多加10;
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

int N,Max_i,Max;
int School[100050];

void Input(){
	int i,s,score;
	scanf("%d",&N);
	for(i=0;i<=N;i++)
		School[i]=0;
	Max_i=Max=0;
	for(i=0;i<N;i++){
		scanf("%d%d",&s,&score);
		School[s]+=score;
		if(School[s]>Max){
			Max_i=s;
			Max=School[s];
		}
	}
}

void Process(){

}

void Display(){
	printf("%d %d\n",Max_i,Max);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}