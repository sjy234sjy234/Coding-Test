#include<iostream>  //利用哈希思想保存多项式;
#include<algorithm>
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

int K;
double Poly[1001];
queue<int> Q;

void Input(){
	int ex;
	double co;
	scanf("%d",&K);
	while(K-->0){
		scanf("%d%lf",&ex,&co);
		Poly[ex]+=co;
	}
	scanf("%d",&K);
	while(K-->0){
		scanf("%d%lf",&ex,&co);
		Poly[ex]+=co;
	}
}

void Process(){
	int i;
	for(i=1000;i>=0;i--)
		if(Poly[i]!=0)
			Q.push(i);
}

void Display(){
	int i;
	printf("%d",Q.size());
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		printf(" %d %.1f",i,Poly[i]);
	}
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