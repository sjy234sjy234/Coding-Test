#include<iostream>  //利用树的层序遍历做,利用哈希Count[]数组记录各层的结点个数;
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

int N,M,K,Ans_Level,Ans_K,Level[101],Count[101];
vector<int> Tree[101];

void Input(){
	int parent,son;
	scanf("%d%d",&N,&M);
	while(M-->0){
		scanf("%d%d",&parent,&K);
		while(K-->0){
			scanf("%d",&son);
			Tree[parent].push_back(son);
		}
	}
}

void Process(){
	int i,j,k;
	Level[1]=1;
	Count[1]++;
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		for(j=0;j<Tree[i].size();j++){
			k=Tree[i][j];
			Level[k]=1+Level[i];
			Count[Level[k]]++;
			Q.push(k);
		}
	}
	Ans_K=0;
	for(i=1;i<=N;i++){
		if(Count[i]>Ans_K){
			Ans_K=Count[i];
			Ans_Level=i;
		}
	}

}

void Display(){
	printf("%d %d\n",Ans_K,Ans_Level);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
