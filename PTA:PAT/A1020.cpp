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

typedef struct BiTNode{
	int data;
	BiTNode *lchild,*rchild;
}*BiTree;

BiTree T;
int N,PostSeq[30],InSeq[30];

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&PostSeq[i]);
	for(i=0;i<N;i++)
		scanf("%d",&InSeq[i]);
}

BiTree GetTree(int low1,int high1,int low2,int high2){
	if(low1<=high1){
		int i;
		for(i=0;InSeq[low2+i]!=PostSeq[high1];i++);
		BiTree root=(BiTree)malloc(sizeof(BiTNode));
		root->data=PostSeq[high1];
		root->lchild=GetTree(low1,low1+i-1,low2,low2+i-1);
		root->rchild=GetTree(low1+i,high1-1,low2+i+1,high2);
		return root;
	}
	else
		return NULL;
}

void LevelOrder(){
	BiTree p;
	queue<BiTree> Q;
	printf("%d",T->data);
	Q.push(T);
	while(!Q.empty()){
		p=Q.front();
		Q.pop();
		if(p->lchild){
			printf(" %d",p->lchild->data);
			Q.push(p->lchild);
		}
		if(p->rchild){
			printf(" %d",p->rchild->data);
			Q.push(p->rchild);
		}
	}
}

void Process(){
	T=GetTree(0,N-1,0,N-1);
	LevelOrder();
}

void Display(){
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
