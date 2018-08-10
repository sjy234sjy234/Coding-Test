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
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
using namespace std;
struct node{
	char data;
	int next;
}SList[100001];

int List1,List2,N,L1,L2;

int Length(int hed){
	int c=0;
	while(hed!=-1){
		c++;
		hed=SList[hed].next;
	}
	return c;
}

void Input(){
	int a,n;
	char d;
	scanf("%d%d%d",&List1,&List2,&N);
	for(int i=0;i<N;i++){
		scanf("%d %c %d",&a,&d,&n);
		SList[a].data=d;
		SList[a].next=n;
	}
	L1=Length(List1);
	L2=Length(List2);
}

void Process(){
	int p1=List1,p2=List2;
	while(L1<L2){
		p2=SList[p2].next;
		L2--;
	}
	while(L1>L2){
		p1=SList[p1].next;
		L1--;
	}
	while(p1!=p2){
		p1=SList[p1].next;
		p2=SList[p2].next;
	}
	if(p1==-1)
		printf("-1\n");
	else
		printf("%05d\n",p1);
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
