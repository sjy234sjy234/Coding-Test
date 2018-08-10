#include<iostream>  //此题不难,但此种处理顺序不易想到;
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

bool Keyboard[128];
char Total[81],Broken[81];

void Input(){
	int i;
	char t;
	scanf("%s%s",Total,Broken);
	for(i=0;i<128;i++)
		Keyboard[i]=false;
	for(i=0;Broken[i]!='\0';i++){
		t=tolower(Broken[i]);
		Keyboard[t]=true;
		t=toupper(Broken[i]);
		Keyboard[t]=true;
	}
	for(i=0;Total[i]!='\0';i++)
		if(Keyboard[Total[i]]==false){
			t=tolower(Total[i]);
			Keyboard[t]=true;
			t=toupper(Total[i]);
		    Keyboard[t]=true;
			printf("%c",t);
		}
	printf("\n");

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