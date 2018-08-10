#include<iostream>  //利用双亲结点表示法;
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

int N,M,K,Max_Level;
bool Mark[101];
int Tree[101],Count[101];

void Input(){
	int parent,son;
	scanf("%d%d",&N,&M);
	while(M-->0){
		scanf("%d%d",&parent,&K);
		Mark[parent]=true;
		while(K-->0){
			scanf("%d",&son);
			Tree[son]=parent;
		}
	}
}

void Process(){
	int i,j,l;
	Max_Level=1;
	for(i=1;i<=N;i++){
		if(!Mark[i]){
			l=1;
			j=i;
			while(Tree[j]!=0){
				l++;
				j=Tree[j];
			}
			Count[l]++;
			if(l>Max_Level)
				Max_Level=l;
		}
	}
}

void Display(){
	int i;
	for(i=1;i<Max_Level;i++)
		printf("%d ",Count[i]);
	printf("%d\n",Count[i]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
