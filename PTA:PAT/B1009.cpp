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

struct word{
	char data[81];
}temp;

stack<word> S;

void Input(){
	while(true){
		cin>>temp.data;
		S.push(temp);
		if(getchar()=='\n')
			break;
	}
}

void Process(){

}

void Display(){
	printf("%s",S.top().data);
	S.pop();
	while(!S.empty()){
		printf(" %s",S.top().data);
		S.pop();
	}
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}