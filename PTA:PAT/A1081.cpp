#include<iostream>  //关键是有一个不断约分的过程;
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

struct rational{
	long long a,b;
}Ans,Temp;

int N;

long long OCG(long long a,long long b){
	while(a&&b){
		if(a>b)
			a%=b;
		else
			b%=a;
	}
	return a>b?a:b;
}

void ADD(){
	long long c;
	Ans.a=Ans.a*Temp.b+Ans.b*Temp.a;
	Ans.b=Ans.b*Temp.b;
	c=OCG(abs(Ans.a),abs(Ans.b));
	Ans.a/=c;
	Ans.b/=c;
}

void Input(){
	long long c;
	scanf("%d",&N);
	Ans.a=0;
	Ans.b=1;
	while(N-->0){
		scanf("%lld/%lld",&Temp.a,&Temp.b);
		c=OCG(abs(Temp.a),abs(Temp.b));
		Temp.a/=c;
		Temp.b/=c;
		ADD();
	}
}

void Process(){
	long long a,b;
	a=abs(Ans.a);
	b=abs(Ans.b);
	if(Ans.a<0)
		printf("-");
	if(a%b==0)
		printf("%lld\n",a/b);
	else{
		if(a/b)
			printf("%lld ",a/b);
		printf("%lld/%lld\n",a%b,b);
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
