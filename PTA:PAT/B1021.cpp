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

char N[1001];
int Count[10];

void Input(){
	int i;
	for(i=0;i<10;i++)
		Count[i]=0;
	scanf("%s",N);
	for(i=0;N[i]!='\0';i++)
		Count[N[i]-'0']++;
}

void Process(){

}

void Display(){
	for(int i=0;i<10;i++)
		if(Count[i])
			printf("%d:%d\n",i,Count[i]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}