#include<iostream>  //此处坑点:当元素个数为0时,仍要多输出一行空行;
#include<algorithm>  //左右两点的思想非常常见;
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

struct num{
	int data;
	int left_max,right_min;
}A[100010];

int N;
priority_queue<int,vector<int>,greater<int>> Ans;
const int INF=1000000010;

void Input(){
	int i;
	scanf("%d",&N);
	A[0].data=-1;
	A[N+1].data=INF;
	for(i=1;i<=N;i++)
		scanf("%d",&A[i]);
}

void Process(){
	int i,temp;
	temp=-1;
	for(i=1;i<=N;i++){
		A[i].left_max=temp;
		if(A[i].data>temp)
			temp=A[i].data;
	}
	temp=INF;
	for(i=N;i>=1;i--){
		A[i].right_min=temp;
		if(A[i].data<temp)
			temp=A[i].data;
	}
	for(i=1;i<=N;i++)
		if(A[i].data>A[i].left_max&&A[i].data<A[i].right_min)
			Ans.push(A[i].data);
}

void Display(){
	printf("%d\n",Ans.size());
	if(!Ans.empty()){
	printf("%d",Ans.top());
	Ans.pop();
	while(!Ans.empty()){
		printf(" %d",Ans.top());
		Ans.pop();
	}
	printf("\n");
	}
	else
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