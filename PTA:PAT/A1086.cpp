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

BiTree T,Last_Node;
bool Last_Op;  //true->push,false->pop;
int N,Temp,C;
char Op[20];
stack<BiTree> S;  //利用栈对中序非递归遍历过程的简单模拟;

void Input(){
	scanf("%d",&N);
	getchar();
	gets(Op);
	sscanf(Op+5,"%d",&Temp);
	T=(BiTree)malloc(sizeof(BiTNode));
	T->data=Temp;
	Last_Node=T;
	Last_Op=true;
	S.push(T);
}

void Process(){  //核心的模拟过程;
	int l=N<<1;
	for(int i=1;i<l;i++){
		gets(Op);
		if(Op[1]=='u'){
			sscanf(Op+5,"%d",&Temp);
			if(Last_Op){  //push+push,last左孩子;
				Last_Op=true;
				Last_Node->lchild=(BiTree)malloc(sizeof(BiTNode));
				Last_Node=Last_Node->lchild;  //Last_Node结点跟随;				
				Last_Node->data=Temp;
			}
			else{  //pop+push,last右孩子;
				Last_Op=true;
				Last_Node->rchild=(BiTree)malloc(sizeof(BiTNode));
				Last_Node=Last_Node->rchild;  //Last_Node结点跟随;
				Last_Node->data=Temp;
			}
			S.push(Last_Node);  //栈模拟操作push;
		}
		else{
			if(Last_Op){  //push+pop,last无左孩;
				Last_Op=false;
				Last_Node->lchild=NULL;
				Last_Node=S.top();  //Last_Node结点跟随;
			}
			else{  //pop+pop,last无右孩;
				Last_Op=false;
				Last_Node->rchild=NULL;
				Last_Node=S.top();  //Last_Node结点跟随;
			}
			S.pop();  //栈模拟操作pop;
		}
	}
	Last_Node->rchild=NULL;
}

void PostOrder(BiTree &root){
	if(root){
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		C++;
		if(C<N)
			printf("%d ",root->data);
		else
			printf("%d\n",root->data);
	}
}
void Display(){
	C=0;
	PostOrder(T);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
