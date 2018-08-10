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

int C1,C2,T;

void Input(){
	scanf("%d%d",&C1,&C2);
	T=C2-C1;
	if(T%100>=50)
		T=T/100+1;
	else
		T/=100;
}

void Process(){
	int h,m,s;
	s=T%60;
	T/=60;
	m=T%60;
	T/=60;
	h=T;
	printf("%02d:%02d:%02d\n",h,m,s);
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