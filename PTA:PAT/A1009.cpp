#include<iostream>  //第二个多项式不必全读入,可边读入边处理;
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

struct node{
	int ex;
	double co;
}Temp;

int K;
double Poly[2001];
vector<node> N1,N2;
queue<int> Q;

void Input(){
	scanf("%d",&K);
	while(K-->0){
		scanf("%d%lf",&Temp.ex,&Temp.co);
		N1.push_back(Temp);
	}
	scanf("%d",&K);
	while(K-->0){
		scanf("%d%lf",&Temp.ex,&Temp.co);
		N2.push_back(Temp);
	}
}

void Process(){
	int i,j;
	for(i=0;i<N1.size();i++)
		for(j=0;j<N2.size();j++)
			Poly[N1[i].ex+N2[j].ex]+=N1[i].co*N2[j].co;
	for(i=2000;i>=0;i--)
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