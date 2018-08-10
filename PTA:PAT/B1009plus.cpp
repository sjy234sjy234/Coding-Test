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

char A[81],Temp[81];

void Input(){
	gets(A);
	int i=strlen(A)-1;
	while(i>=0){
		for(;i>0&&A[i]!=' ';i--);
		if(A[i]==' '){
			sscanf(A+i+1,"%s",Temp);
			printf("%s ",Temp);
		}
		else if(i==0){
			sscanf(A,"%s",Temp);
			printf("%s\n",Temp);
		}
		i--;
	}
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