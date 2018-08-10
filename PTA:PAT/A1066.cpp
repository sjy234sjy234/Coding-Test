#include<iostream>  //Height(),BF(),Insert(),UpDateHeight();
#include<algorithm>  //VSÓÐBUG;
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
	int data,height;
	BiTNode *lchild,*rchild;
}*BiTree;

BiTree T;
int N;

BiTree NewNode(int data){
	BiTree root=(BiTree)malloc(sizeof(BiTNode));
	root->data=data;
	root->height=1;
	root->lchild=root->rchild=NULL;
	return root;
}

int Height(BiTree &root){
	if(root)
		return root->height;
	else
		return 0;
}

void UpDateHeight(BiTree &root){
	root->height=1+max(Height(root->lchild),Height(root->rchild));
}

int BF(BiTree &root){
	return Height(root->lchild)-Height(root->rchild);
}

void LeftRotate(BiTree &root){
	BiTree temp=root->rchild;
	root->rchild=temp->lchild;
	temp->lchild=root;
	UpDateHeight(root);
	UpDateHeight(temp);
	root=temp;
}

void RightRotate(BiTree &root){
	BiTree temp=root->lchild;
	root->lchild=temp->rchild;
	temp->rchild=root;
	UpDateHeight(root);
	UpDateHeight(temp);
	root=temp;
}

void Insert(BiTree &root,int data){
	if(!root)
		root=NewNode(data);
	else if(data<root->data){
		Insert(root->lchild,data);
		UpDateHeight(root);
		if(BF(root)==2){
			if(BF(root->lchild)==1)
				RightRotate(root);
			else{
				LeftRotate(root->lchild);
				RightRotate(root);
			}
		}
	}
	else{
		Insert(root->rchild,data);
        UpDateHeight(root);  
		if(BF(root)==-2){
			if(BF(root->rchild)==-1)
				LeftRotate(root);
			else{
				RightRotate(root->rchild);
				LeftRotate(root);
			}
		}
	}
}

void Input(){
	int data;
	T=NULL;
	scanf("%d",&N);
	while(N-->0){
		scanf("%d",&data);
		Insert(T,data);
	}
}

void Process(){
	printf("%d\n",T->data);
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
