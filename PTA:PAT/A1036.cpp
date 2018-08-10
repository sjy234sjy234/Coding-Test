#include<iostream>  //对于输入由空格分隔的情况,只要在scanf("")中添加空格即可;
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

struct student{
	char name[15],gender,num[15];
	int score;
}Temp,Boy,Girl;

int N;

void Input(){
	scanf("%d",&N);
	Boy.score=110;
	Girl.score=-1;
}

void Process(){
	while(N-->0){
		scanf("%s %c %s %d",Temp.name,&Temp.gender,&Temp.num,&Temp.score);  
		if(Temp.gender=='M'){
			if(Temp.score<Boy.score)
				Boy=Temp;
		}
		else{
			if(Temp.score>Girl.score)
				Girl=Temp;
		}
	}
}

void Display(){
	if(Girl.score<0)
		printf("Absent\n");
	else
		printf("%s %s\n",Girl.name,Girl.num);
	if(Boy.score>100)
		printf("Absent\n");
	else
		printf("%s %s\n",Boy.name,Boy.num);
	if(Girl.score<0||Boy.score>100)
		printf("NA\n");
	else
		printf("%d\n",Girl.score-Boy.score);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}