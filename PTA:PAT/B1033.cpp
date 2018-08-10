#include<iostream>  //坑点:第一个字符串可能为空的,因此必须用gets()获取第一个;
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
char Broken[100050],Str[100050];

void Input(){
	gets(Broken);
	scanf("%s",Str);
}

void Process(){
	int i,j;
	for(i=0;i<128;i++)
		Mark[i]=true;
	for(i=0;Broken[i]!='\0';i++){
		Mark[Broken[i]]=false;
		Broken[i]=tolower(Broken[i]);
		Mark[Broken[i]]=false;
		if(Broken[i]=='+')
			for(j='A';j<='Z';j++)
				Mark[j]=false;
	}
}

void Display(){
	int i;
	for(i=0;Str[i]!='\0';i++)
		if(Mark[Str[i]])
			printf("%c",Str[i]);
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