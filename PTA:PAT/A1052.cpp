#include<iostream>  //此题最大的坑点,就是可能结点数为0;
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
	bool operator<(const record &b)const{
		return data<b.data;
	}
}Rec;

set<record> S;  //利用set递增存放结点信息,并利用迭代器进行输出操作;
set<record>::iterator It; 
int N,List;

int Length(int hed){
	int c=0;
	while(hed!=-1){
		c++;
		Rec.address=hed;
		Rec.data=SList[hed].data;
		S.insert(Rec);
		hed=SList[hed].next;
	}
	return c;
}

void Input(){
	int i,a,n,d;
	scanf("%d%d",&N,&List);
	for(i=0;i<N;i++){
		scanf("%d%d%d",&a,&d,&n);
		SList[a].data=d;
		SList[a].next=n;
	}
	N=Length(List);
}

void Process(){
	if(N==0)
		printf("0 -1\n");
	else{
		printf("%d",S.size());
		for(It=S.begin();It!=S.end();It++)
			printf(" %05d\n%05d %d",It->address,It->address,It->data);
		printf(" -1\n");
	}
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
