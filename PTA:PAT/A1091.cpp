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

struct status{
	int i,j,k;
}Temp1,Temp2;

int M,N,L,T,C,Ans;
int Go[6][3]={{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};
bool Cube[60][1286][128];
queue<status> Q;

void Input(){
	int i,j,k;
	scanf("%d%d%d%d",&M,&N,&L,&T);
	for(i=0;i<L;i++)
		for(j=0;j<M;j++)
			for(k=0;k<N;k++){
				scanf("%d",&Cube[i][j][k]);
				Cube[i][j][k]=!Cube[i][j][k];
			}
}

void BFS(int i,int j,int k){
	int p,ti,tj,tk;
	Temp1.i=i;
	Temp1.j=j;
	Temp1.k=k;
	Q.push(Temp1);
	Cube[i][j][k]=true;
	C++;
	while(!Q.empty()){
		Temp1=Q.front();
		Q.pop();
		for(p=0;p<6;p++){
			ti=Temp1.i+Go[p][0];
			tj=Temp1.j+Go[p][1];
			tk=Temp1.k+Go[p][2];
			if(ti>=0&&ti<L&&tj>=0&&tj<M&&tk>=0&&tk<N&&!Cube[ti][tj][tk]){
				Cube[ti][tj][tk]=true;
				C++;
				Temp2.i=ti;
				Temp2.j=tj;
				Temp2.k=tk;
				Q.push(Temp2);
			}
		}
	}
}

void Process(){
	Ans=0;
	int i,j,k;
	for(i=0;i<L;i++)
		for(j=0;j<M;j++)
			for(k=0;k<N;k++){
				if(!Cube[i][j][k]){
					C=0;
					BFS(i,j,k);
					if(C>=T)
						Ans+=C;
				}
			}
}

void Display(){
	printf("%d\n",Ans);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
