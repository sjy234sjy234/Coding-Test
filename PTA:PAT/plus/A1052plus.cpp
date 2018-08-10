#include<iostream>  //利用正规的链表插入排序法进行排序操作;
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
	int data,next;
}SList[100000];

int N,List;

int Length(int hed){
	int c=0;
	while(hed!=-1){
		c++;
		hed=SList[hed].next;
	}
	return c;
}

void Input(){
	int a,d,n;
	scanf("%d%d",&N,&List);
	while(N-->0){
		scanf("%d%d%d",&a,&d,&n);
		SList[a].data=d;
		SList[a].next=n;
	}
	N=Length(List);
}

void Process(){
	int p,q,r;
	p=List;
	SList[0].next=-1;
	while(p!=-1){
		q=SList[p].next;
		r=0;
		while(SList[r].next!=-1&&SList[SList[r].next].data<SList[p].data)
			r=SList[r].next;
		SList[p].next=SList[r].next;
		SList[r].next=p;
		p=q;
	}
}

void Display(){
	if(N==0)
		printf("0 -1\n");
	else{
		int p=SList[0].next;
		printf("%d %05d\n",N,p);
		while(SList[p].next!=-1){
			printf("%05d %d %05d\n",p,SList[p].data,SList[p].next);
			p=SList[p].next;
		}
		printf("%05d %d %d\n",p,SList[p].data,SList[p].next);
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
