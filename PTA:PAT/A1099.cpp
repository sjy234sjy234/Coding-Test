#include<iostream>  //中序和层序过一遍即可;
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
	int data;
	int lchild,rchild;
}Tree[100];

int N,K,Data[100];

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d%d",&Tree[i].lchild,&Tree[i].rchild);
	for(i=0;i<N;i++)
		scanf("%d",&Data[i]);
	sort(Data,Data+N);
}

void InOrder(int root){
	if(root!=-1){
		InOrder(Tree[root].lchild);
		Tree[root].data=Data[K++];
		InOrder(Tree[root].rchild);
	}
}

void LevelOrder(){
	int i;
	printf("%d",Tree[0].data);
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		if(Tree[i].lchild!=-1){
			printf(" %d",Tree[Tree[i].lchild].data);
			Q.push(Tree[i].lchild);
		}
		if(Tree[i].rchild!=-1){
			printf(" %d",Tree[Tree[i].rchild].data);
			Q.push(Tree[i].rchild);
		}
	}
	printf("\n");
}

void Process(){
	K=0;
	InOrder(0);
	LevelOrder();
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
