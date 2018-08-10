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

int Count[10];

void Input(){
	for(int i=0;i<10;i++)
		scanf("%d",&Count[i]);
}

void Process(){
	int i;
	for(i=1;i<10;i++)
		if(Count[i]){
			printf("%d",i);
			Count[i]--;
			break;
		}
	for(i=0;i<10;i++){
		while(Count[i]-->0)
			printf("%d",i);
	}
	printf("\n");
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