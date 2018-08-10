#include<iostream>  //此题关键是在结构体中加入rank域以区分学生等级;
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
	int num,d,c,s,rank;
	bool operator<(const student &b)const{
		if(rank!=b.rank)
			return rank<b.rank;
		else if(s!=b.s)
			return s>b.s;
		else if(d!=b.d)
			return d>b.d;
		else
			return num<b.num;
	}
}Stu[100000];

int N,Low,High,K;

void Input(){
	int i,num,d,c;
	scanf("%d%d%d",&N,&Low,&High);
	for(i=K=0;i<N;i++){
		scanf("%d%d%d",&num,&d,&c);
		if(d>=Low&&c>=Low){
			Stu[K].num=num;
			Stu[K].d=d;
			Stu[K].c=c;
			Stu[K].s=d+c;
			if(d>=High&&c>=High)
				Stu[K].rank=1;
			else if(d>=High)
				Stu[K].rank=2;
			else if(d>=c)
				Stu[K].rank=3;
			else
				Stu[K].rank=4;
			K++;
		}
	}
}

void Process(){
	sort(Stu,Stu+K);
}

void Display(){
	printf("%d\n",K);
	for(int i=0;i<K;i++)
		printf("%08d %d %d\n",Stu[i].num,Stu[i].d,Stu[i].c);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}