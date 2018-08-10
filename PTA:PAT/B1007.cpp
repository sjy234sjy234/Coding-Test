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

int N,Count;

void Input(){
	scanf("%d",&N);
}

bool IsPrime(int x){
	int l=sqrt((double)x);
	for(int i=2;i<=l;i++)
		if(x%i==0)
			return false;
	return true;
}

void Process(){
	Count=0;
	int i=5;
	while(i<=N){
		if(IsPrime(i)){
			Count++;
			i+=2;
		}
		else{
			i+=2;
			while(!IsPrime(i))
				i+=2;
			i+=2;
		}
	}
}

void Display(){
	printf("%d\n",Count);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}