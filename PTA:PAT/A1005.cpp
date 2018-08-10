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

char N[150];
char Refer[10][8]={"zero","one","two","three","four","five","six","seven","eight","nine"};
int Ans;
stack<int> S;

void Input(){
	scanf("%s",N);
}

void Process(){
	Ans=0;
	for(int i=0;N[i]!='\0';i++)
		Ans+=N[i]-'0';
	while(Ans>0){
		S.push(Ans%10);
		Ans/=10;
	}
}

void Display(){
	if(S.empty())
		printf("zero\n");
	else{	
		int i;	
		i=S.top();	
		S.pop();
		printf("%s",Refer[i]);
		while(!S.empty()){
			i=S.top();
			S.pop();
			printf(" %s",Refer[i]);
		}
		printf("\n");
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}