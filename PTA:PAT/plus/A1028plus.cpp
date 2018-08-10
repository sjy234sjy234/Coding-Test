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

int N,C;

struct student{
	int num,score;
	char name[10];
	bool operator<(const student &b)const{
		switch(C){
		case 1:return num<b.num;
		case 2:
			int tmp;  //此处tmp一定要在下行赋值才可以通过;
			tmp=strcmp(name,b.name);
			if(tmp)return tmp<0;   
			else return num<b.num;
		case 3:if(score!=b.score)return score<b.score;
			   else return num<b.num;
		}
	}
}Stu[100000];

void Input(){
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++)
		scanf("%d%s%d",&Stu[i].num,Stu[i].name,&Stu[i].score);
	sort(Stu,Stu+N);
}

void Process(){

}

void Display(){
	for(int i=0;i<N;i++)
		printf("%06d %s %d\n",Stu[i].num,Stu[i].name,Stu[i].score);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}