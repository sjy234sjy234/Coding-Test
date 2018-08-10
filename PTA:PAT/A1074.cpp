#include<iostream>  //此题还是相当有难度的;
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

struct LNode{
	int data,next;
}SList[100001];

int List,N,K;

int CountNode(){
	int c=0,p=100000;
	while(SList[p].next!=-1){
		c++;
		p=SList[p].next;
	}
	return c;
}

void Input(){
	int i,a,d,n;
	scanf("%d%d%d",&List,&N,&K);
	SList[100000].next=List;
	for(i=0;i<N;i++){
		scanf("%d%d%d",&a,&d,&n);
		SList[a].data=d;
		SList[a].next=n;
	}
	N=CountNode();
}

void Process(){
	int i,t=N/K;
	int p,q,head,tail;
	p=SList[100000].next;
	SList[100000].next=-1;
	head=tail=100000;
	while(t-->0){  //核心算法部分,执行t次反转;
		for(i=1;i<=K;i++){  //每次反转K个结点;
			q=SList[p].next;
			SList[p].next=SList[head].next;
			SList[head].next=p;
			p=q;
			if(i==1)  //头结点跟随尾结点;
				tail=SList[head].next;
		}
		head=tail;
	}
	if(N>t*K)
		SList[head].next=p;
}

void Display(){
	int p=SList[100000].next;
	while(p!=-1&&SList[p].next!=-1){
		printf("%05d %d %05d\n",p,SList[p].data,SList[p].next);
		p=SList[p].next;
	}
	printf("%05d %d %d\n",p,SList[p].data,SList[p].next);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}