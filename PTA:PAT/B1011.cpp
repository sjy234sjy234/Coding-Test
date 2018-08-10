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

char Refer[2][6]={"false","true"};
int Ans[10],T;
long long A,B,C;

void Input(){
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		Ans[i]=A+B>C?1:0;
	}
}

void Process(){

}

void Display(){
	for(int i=1;i<=T;i++)
		printf("Case #%d: %s\n",i,Refer[Ans[i-1]]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}