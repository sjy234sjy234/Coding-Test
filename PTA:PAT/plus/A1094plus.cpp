#include<iostream>  //此处使用了双亲结点表示法和哈希数组Count[]记录各层结点数的方法;
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

int N,M,K,Ans_Level,Ans_K;
int Tree[101],Count[101];

void Input(){
	int parent,son;
	scanf("%d%d",&N,&M);
	while(M-->0){
		scanf("%d%d",&parent,&K);
		while(K-->0){
			scanf("%d",&son);
			Tree[son]=parent;
		}
	}
}

void Process(){
	int i,j,l;
	for(i=1;i<=N;i++){
		j=i;
		l=1;
		while(Tree[j]!=0){
			j=Tree[j];
			l++;
		}
		Count[l]++;
	}
	Ans_K=1;
	Ans_Level=1;
	for(i=2;i<=N;i++)
		if(Count[i]>Ans_K){
			Ans_K=Count[i];
			Ans_Level=i;
		}
}

void Display(){
	printf("%d %d\n",Ans_K,Ans_Level);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
