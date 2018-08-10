#include<iostream>  //通常涉及到键盘字符,肯定都涉及到哈希;
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

bool Mark[128];
char S1[10010],S2[10010];

void Input(){
	int i;
	gets(S1);
	gets(S2);
	for(i=0;i<128;i++)
		Mark[i]=true;
	for(i=0;S2[i]!='\0';i++)
		Mark[S2[i]]=false;
	for(i=0;S1[i]!='\0';i++)
		if(Mark[S1[i]])
			printf("%c",S1[i]);
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