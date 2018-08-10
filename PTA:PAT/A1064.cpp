#include<iostream>  //对于完全二叉树序列的下标应该从1开始;
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

int N,InSeq[1000],Complete[1001];

void Input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%d",&InSeq[i]);
	sort(InSeq,InSeq+N);
}

void GetComp(int root,int low,int high){  //利用递归,逻辑非常之清晰;
	if(low<high){  //low为树首结点坐标,high为末结点坐标;
		int n,h,k,l,pos;
		n=high-low+1;  //结点个数;
		h=log((double)n)/log(2.0);  //高度-1;
		k=n-pow(2.0,h)+1;  //最低层次叶子个数;
		l=pow(2.0,h);  //最低层满时叶子个数;
		if(2*k<l)	//若最低层不过半;
			pos=k+pow(2.0,h-1)-1;  //确定根的偏移量;
		else  //若最底层过半;
			pos=pow(2.0,h)-1;  //确定根的偏移量;
		Complete[root]=InSeq[low+pos];  //将根结点装入Complete函数;
		GetComp(root*2,low,low+pos-1);  //装左子树;
		GetComp(root*2+1,low+pos+1,high);  //装右子树;
	}
	else if(low==high)  //若结点个数1,直接装入;
		Complete[root]=InSeq[low];
}

void Process(){
	GetComp(1,0,N-1);
}

void Display(){
	printf("%d",Complete[1]);
	for(int i=2;i<=N;i++)
		printf(" %d",Complete[i]);
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
