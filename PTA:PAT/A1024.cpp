#include<iostream>  //对大整数的灵活处理,此处用到了ADD(),REVERSE(),ISPALIN();
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

struct bignum{
	int data[100];
	int num;
}N,R;

int K,Step;
long long N0;

void Input(){
	scanf("%lld%d",&N0,&K);
}


void GetN(){
	if(N0==0){
		N.num=1;
		N.data[0]=0;
		return;
	}
	N.num=0;
	while(N0>0){
		N.data[N.num++]=N0%10;
		N0/=10;
	}
}

bool IsPalin(){
	int i,l=N.num/2;
	for(i=0;i<l&&N.data[i]==N.data[N.num-1-i];i++);
	if(i==l)
		return true;
	else
		return false;
}

void Reverse(){
	int i;
	for(i=0;i<N.num;i++)
		R.data[N.num-1-i]=N.data[i];
	R.num=N.num;
}

void ADD(){
	int i,temp=0;
	for(i=0;i<N.num;i++){
		temp+=N.data[i]+R.data[i];
		N.data[i]=temp%10;
		temp/=10;
	}
	if(temp)
		N.data[N.num++]=temp;
}

void Process(){
	Step=0; 					
	GetN();			
	while(!IsPalin()&&Step<K){					
		Reverse();					
		ADD();					
		Step++;			
	}
}

void Display(){
	int i;
	for(i=N.num-1;i>=0;i--)
		printf("%d",N.data[i]);
	printf("\n%d\n",Step);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
