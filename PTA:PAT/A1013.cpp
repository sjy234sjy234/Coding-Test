#include<iostream>  //实际上是利用DFS或者BFS求连通分量的个数;
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

int N,M,K,C;
bool Mark[1001];
vector<int> Graph[1001];

void Input(){
	int c1,c2;
	scanf("%d%d%d",&N,&M,&K);
	while(M-->0){
		scanf("%d%d",&c1,&c2);
		Graph[c1].push_back(c2);
		Graph[c2].push_back(c1);
	}
}

void DFS(int i){
	int j,k;
	Mark[i]=true;
	for(j=0;j<Graph[i].size();j++){
		k=Graph[i][j];	
		if(!Mark[k])
			DFS(k);
	}
}

void Process(){
	int i,check;
	while(K-->0){
		for(i=1;i<=N;i++)
			Mark[i]=false;
		scanf("%d",&check);
		Mark[check]=true;
		C=-1;
		for(i=1;i<=N;i++)
			if(!Mark[i]){
				C++;
				DFS(i);
			}
		printf("%d\n",C);
	}
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
