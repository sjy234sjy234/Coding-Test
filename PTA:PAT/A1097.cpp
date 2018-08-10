#include<iostream>  //虽然考察的都是链表,但是做题目时可以利用不同数据结构加以模拟,使过程更加简单;
#include<algorithm>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
using namespace std;
struct node{
	int address,data,next;
}SList[100000];

struct record{
	int address,data;
}Rec;

int List,N;
bool Mark[10001];
queue<record> Q1,Q2;

void Input(){
	int a,d,n;
	scanf("%d%d",&List,&N);
	while(N-->0){
		scanf("%d%d%d",&a,&d,&n);
		SList[a].data=d;
		SList[a].next=n;
	}
}

void Process(){
	int d,p=List;
	while(p!=-1){
		Rec.address=p;
		Rec.data=SList[p].data;
		d=abs(SList[p].data);
		if(Mark[d])
			Q2.push(Rec);
		else
			Q1.push(Rec);
		Mark[d]=true;
		p=SList[p].next;
	}
}

void Display(){
	if(!Q1.empty()){
		Rec=Q1.front();
		Q1.pop();
		printf("%05d %d",Rec.address,Rec.data);
		while(!Q1.empty()){
			Rec=Q1.front();
			Q1.pop();
			printf(" %05d\n%05d %d",Rec.address,Rec.address,Rec.data);
		}
		printf(" -1\n");
	}
	if(!Q2.empty()){
		Rec=Q2.front();
		Q2.pop();
		printf("%05d %d",Rec.address,Rec.data);
		while(!Q2.empty()){
			Rec=Q2.front();
			Q2.pop();
			printf(" %05d\n%05d %d",Rec.address,Rec.address,Rec.data);
		}
		printf(" -1\n");
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
