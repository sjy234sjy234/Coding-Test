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

struct student{
	char name[11],num[11];
	int score;
}Stu[101];

int N,Min,Max;

void Input(){
	int i;
	Min=Max=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s%s%d",Stu[i].name,Stu[i].num,&Stu[i].score);
		if(Stu[i].score>Stu[Max].score)
			Max=i;
		if(Stu[i].score<Stu[Min].score)
			Min=i;
	}
}

void Process(){

}

void Display(){
	printf("%s %s\n",Stu[Max].name,Stu[Max].num);
	printf("%s %s\n",Stu[Min].name,Stu[Min].num);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}