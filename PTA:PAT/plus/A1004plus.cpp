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

int N,M,K,Max_Level;
int Level[101],Count[101];
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
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		Max_Level=Level[i];  //Max_Level放置的位置有讲究;
		if(Tree[i].empty())
			Count[Level[i]]++;
		else{
			for(j=0;j<Tree[i].size();j++){
				k=Tree[i][j];
				Level[k]=1+Level[i];
				Q.push(k);
			}
		}
	}
}

void Display(){
	for(int i=1;i<Max_Level;i++)
		printf("%d ",Count[i]);
	printf("%d\n",Count[Max_Level]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
