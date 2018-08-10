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

long long A,B,Ans;

void Input(){
	long long g,s,k;
	scanf("%lld.%lld.%lld",&g,&s,&k);
	A=g*17*29+s*29+k;
	scanf("%lld.%lld.%lld",&g,&s,&k);
	B=g*17*29+s*29+k;
	Ans=A+B;
	k=Ans%29;
	Ans/=29;
	s=Ans%17;
	Ans/=17;
	g=Ans;
	printf("%lld.%lld.%lld\n",g,s,k);
}

void Process(){

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