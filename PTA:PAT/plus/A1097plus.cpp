#include<iostream>  //利用原始的链表操作方法求解,注意头结点的灵活添加和删除;
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
}SList[100002];

bool Mark[10001];
const int List1=100000,List2=100001;
int N,List;

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
	int temp,p,q,tail1,tail2;
	tail1=List1;
	tail2=List2;
	p=List;
	while(p!=-1){
		q=SList[p].next;
		temp=abs(SList[p].data);
		if(Mark[temp]){
			SList[tail2].next=p;
			tail2=p;
		}
		else{
			Mark[temp]=true;
			SList[tail1].next=p;
			tail1=p;
		}
		p=q;
	}
	SList[tail1].next=-1;
	SList[tail2].next=-1;
}

void Display(){
	int p;
	p=SList[List1].next;
	if(p!=-1){
		while(SList[p].next!=-1){
			printf("%05d %d %05d\n",p,SList[p].data,SList[p].next);
			p=SList[p].next;
		}
		printf("%05d %d -1\n",p,SList[p].data);
	}
	p=SList[List2].next;
	if(p!=-1){
		while(SList[p].next!=-1){
			printf("%05d %d %05d\n",p,SList[p].data,SList[p].next);
			p=SList[p].next;
		}
		printf("%05d %d -1\n",p,SList[p].data);
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
