#include<iostream>  //在使用折半查找的时候,特别要注意的是low和high可能出现越界的情况;
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
	char name[15],id[15];
	int score;
	bool operator<(const student &b)const{
		return score>b.score;
	}
}Stu[101];

int N,Grade1,Grade2;

void Input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%s%s%d",Stu[i].name,Stu[i].id,&Stu[i].score);
	scanf("%d%d",&Grade1,&Grade2);
	sort(Stu,Stu+N);
}

void Process(){
	bool flag=true;
	for(int i=0;i<N;i++)
		if(Stu[i].score<=Grade2&&Stu[i].score>=Grade1){  //这种利用条件判断进行查找的方法才正规,不要想着去定左右坐标才输出,因为坐标是可能越界的,处理起来非常麻烦;
			printf("%s %s\n",Stu[i].name,Stu[i].id);
			flag=false;
		}
	if(flag)
		printf("NONE\n");
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