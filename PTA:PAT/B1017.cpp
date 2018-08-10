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

char A[1001];
int B,R;

void Input(){
	scanf("%s%d",A,&B);
}

void Process(){
	int i;
	for(i=R=0;A[i]!='\0';i++){
		R=A[i]-'0'+10*R;
		A[i]='0'+R/B;
		R%=B;
	}
}

void Display(){
	int i;
	for(i=0;A[i]=='0';i++);
	if(A[i]=='\0')
		printf("0 %d\n",R);
	else
		printf("%s %d\n",A+i,R);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}