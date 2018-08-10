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

int N,D,Temp;
bool Flag;

bool IsPrime(int x){
	if(x<2)
		return false;
	int l=sqrt((double)x),i;
	for(i=2;i<=l;i++)
		if(x%i==0)
			return false;
	return true;
}

void Input(){
	scanf("%d",&D);
	Flag=IsPrime(N);
}

void Process(){
	if(Flag){
		Temp=0;
		while(N>0){
			Temp=Temp*D+N%D;
			N/=D;
		}
		if(!IsPrime(Temp))
			Flag=false;
	}
}

void Display(){
	if(Flag)
		printf("Yes\n");
	else
		printf("No\n");
}

int main(){
	while(scanf("%d",&N)!=EOF&&N>=0){
	Input();
	Process();
	Display();
	}
	return 0;
}
