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

int M,N,Count;

void Input(){
	scanf("%d%d",&M,&N);
}

bool IsPrime(int x){
	int l=sqrt((double)x);
	for(int i=2;i<=l;i++)
		if(x%i==0)
			return false;
	return true;
}

void Process(){
	int i,t;
	Count=0;
	for(i=2;Count<N;i++){
		if(IsPrime(i)){
			Count++;
			t=Count-M;
			if(t>=0){
				printf("%d",i);
				if(Count<N&&(t+1)%10)
					printf(" ");
				else
					printf("\n");
			}
		}
	}
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