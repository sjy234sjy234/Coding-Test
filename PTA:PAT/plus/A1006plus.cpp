#include<iostream>  //实际上可以利用复用在结构体中只构造一个time;
#include<algorithm>  //结构体中嵌套结构体一定要加struct,否则编译不通过;
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

struct time{
	int h,m,s;
	bool operator<(const time &b)const{
		if(h!=b.h)
			return h<b.h;
		else if(m!=b.m)
			return m<b.m;
		else
			return s<b.s;
	}
};

struct student{
	char ID[20];
	struct time t;
}Temp,Early,Late;

int M;

void Input(){
	Early.t.h=24;
	Early.t.m=Early.t.s=0;
	Late.t.h=Late.t.m=Late.t.s=0;
	scanf("%d",&M);
}

void Process(){
	while(M--){
		scanf("%s%d:%d:%d%",Temp.ID,&Temp.t.h,&Temp.t.m,&Temp.t.s);
		if(Temp.t<Early.t)
			Early=Temp;
		scanf("%d:%d:%d",&Temp.t.h,&Temp.t.m,&Temp.t.s);		
		if(Late.t<Temp.t)
			Late=Temp;
	}
}

void Display(){
	printf("%s %s\n",Early.ID,Late.ID);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}