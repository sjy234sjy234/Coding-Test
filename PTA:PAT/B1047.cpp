#include<iostream>  //哈希的简单应用;
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

int N,Max,Max_t,Count[1001];

void Input(){
	int team,num,score;
	scanf("%d",&N);
	Max=0;
	while(N-->0){
		scanf("%d-%d%d",&team,&num,&score);
		Count[team]+=score;
		if(Count[team]>Max){
			Max=Count[team];
			Max_t=team;
		}
	}
}

void Process(){

}

void Display(){
	printf("%d %d\n",Max_t,Max);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}