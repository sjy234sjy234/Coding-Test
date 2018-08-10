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
	string name;
	bool operator<(const student &b)const{
		switch(C){
		case 1:return num<b.num;
		case 2:if(name!=b.name)return name<b.name;
			   else return num<b.num;
		case 3:if(score!=b.score)return score<b.score;
			   else return num<b.num;
		}
	}
}Stu[100000];

void Input(){
	scanf("%d%d",&N,&C);
	for(int i=0;i<N;i++)
		cin>>Stu[i].num>>Stu[i].name>>Stu[i].score;
	sort(Stu,Stu+N);
}

void Process(){

}

void Display(){
	for(int i=0;i<N;i++)
		printf("%06d %s %d\n",Stu[i].num,Stu[i].name.c_str(),Stu[i].score);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}