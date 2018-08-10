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

struct node{  //利用静态数组来完成二叉树的模拟遍历,parent域或者Mark[]数组都可以用来完成对根的寻找;
	int lchild,rchild,parent;
}Tree[10];

int N,Root,C;
bool Mark[10];

void Input(){
	int i;
	char s[4],l,r;
	scanf("%d",&N);
	getchar();
	for(i=0;i<N;i++){
		gets(s);
		l=s[0];
		r=s[2];
		if(l=='-')
			Tree[i].lchild=-1;
		else{
			Tree[i].lchild=l-'0';
			Mark[Tree[i].lchild]=true;
		}
		if(r=='-')
			Tree[i].rchild=-1;
		else{
			Tree[i].rchild=r-'0';
			Mark[Tree[i].rchild]=true;
		}
	}
	for(i=0;i<N;i++)
		if(!Mark[i]){
			Root=i;
			break;
		}
}

void LevelOrder(int &root){
	int i;
	queue<int> Q;
	Q.push(root);
	printf("%d",root);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		if(Tree[i].rchild!=-1){
			Q.push(Tree[i].rchild);
			printf(" %d",Tree[i].rchild);
		}
		if(Tree[i].lchild!=-1){
			Q.push(Tree[i].lchild);
			printf(" %d",Tree[i].lchild);
		}
	}
	printf("\n");
}

void InOrder(int &root){
	if(root!=-1){
		InOrder(Tree[root].rchild);
		C++;
		if(C<N)
			printf("%d ",root);
		else
			printf("%d\n",root);
		InOrder(Tree[root].lchild);
	}
}

void Process(){
	LevelOrder(Root);
	C=0;
	InOrder(Root);
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
