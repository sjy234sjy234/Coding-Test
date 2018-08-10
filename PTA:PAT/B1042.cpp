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

char A[1050];
int Count[26],Max;

void Input(){
	int i;
	gets(A);
	for(i=0;i<26;i++)
		Count[i]=0;
}

void Process(){
	Max=-1;
	int tmp;
	for(int i=0;A[i]!='\0';i++){  
		A[i]=tolower(A[i]);
		if(A[i]<='z'&&A[i]>='a'){
			tmp=A[i]-'a';
			Count[tmp]++;
			if(Max==-1)  //在循环计数的过程中直接判断出最大下标Max;
				Max=tmp;
			else if(Count[tmp]>Count[Max])
				Max=tmp;
			else if(Count[tmp]==Count[Max]&&tmp<Max)
				Max=tmp;
		}
	}
}

void Display(){
	char ans=Max+'a';
	printf("%c %d\n",ans,Count[Max]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}