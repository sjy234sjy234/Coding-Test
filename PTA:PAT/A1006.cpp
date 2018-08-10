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
}Earlist,Latest,In,Out;

int M;
char Early[20],Late[20],Temp[20];

void Input(){
	Earlist.h=24;
	Earlist.m=Earlist.s=0;
	Latest.h=Latest.m=Latest.s=0;
	scanf("%d",&M);
}

void Process(){

	while(M--){
		scanf("%s%d:%d:%d%d:%d:%d",Temp,&In.h,&In.m,&In.s,&Out.h,&Out.m,&Out.s);
		if(In<Earlist){
			strcpy(Early,Temp);
			Earlist=In;  //结构体也和vector变量一样可以直接赋值的,不需要重载;
		}
		if(Latest<Out){
			strcpy(Late,Temp);
			Latest=Out;
		}
	}
}

void Display(){
	printf("%s %s\n",Early,Late);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}