#include<iostream>  //此题难点在于对相等元素情况的处理,需要写两个不同的递归判断转化函数;
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

bool Flag;
int N;
int PreSeq[1000],InSeq[1000],PostSeq[1000];

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&PreSeq[i]);
		InSeq[i]=PreSeq[i];
	}
	sort(InSeq,InSeq+N);
}

void Reverse(){
	int i,t,half=N>>1;
	for(i=0;i<half;i++){
		t=InSeq[i];
		InSeq[i]=InSeq[N-1-i];
		InSeq[N-1-i]=t;
	}
}

void GetPost1(int low1,int high1,int low2,int high2,int low3,int high3){
	if(Flag&&low1<=high1){
		int i;
		PostSeq[high3]=PreSeq[low1];
		for(i=0;i<=high2-low2&&InSeq[low2+i]!=PostSeq[high3];i++);  //由于相等元素只在右边,找根结点必须从左边开始;
		if(i>high2-low2){
			Flag=false;
			return;
		}
		if(Flag)
			GetPost1(low1+1,low1+i,low2,low2+i-1,low3,low3+i-1);
		if(Flag)
			GetPost1(low1+i+1,high1,low2+i+1,high2,low3+i,high3-1);
	}
}

void GetPost2(int low1,int high1,int low2,int high2,int low3,int high3){
	if(Flag&&low1<=high1){
		int i;
		PostSeq[high3]=PreSeq[low1];
		for(i=high2-low2;i>=0&&InSeq[low2+i]!=PostSeq[high3];i--);  //由于相等元素只在左边,找根结点必须从右边开始;
		if(i<0){
			Flag=false;
			return;
		}
		if(Flag)
			GetPost2(low1+1,low1+i,low2,low2+i-1,low3,low3+i-1);
		if(Flag)
			GetPost2(low1+i+1,high1,low2+i+1,high2,low3+i,high3-1);
	}
}

void Process(){
	Flag=true;
	GetPost1(0,N-1,0,N-1,0,N-1);
	if(Flag)
		return;
	else{
		Reverse();
		Flag=true;
		GetPost2(0,N-1,0,N-1,0,N-1);
	}
}

void Display(){
	if(Flag){
		printf("YES\n");
		printf("%d",PostSeq[0]);
		for(int i=1;i<N;i++)
			printf(" %d",PostSeq[i]);
		printf("\n");
	}
	else
		printf("NO\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
