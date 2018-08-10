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

int Ans;
char N[101];
char Refer[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

void Input(){
	scanf("%s",N);
}

void Process(){
	Ans=0;
	for(int i=0;N[i]!='\0';i++)
		Ans+=N[i]-'0';
}

void Display(){
	if(Ans==0)
		printf("ling\n");
	else{
		stack<int> S;
		while(Ans>0){
			S.push(Ans%10);
			Ans/=10;
		}
		printf("%s",Refer[S.top()]);
		S.pop();
		while(!S.empty()){
			printf(" %s",Refer[S.top()]);
			S.pop();
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