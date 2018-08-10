#include<iostream>  //简单树的层序遍历的模拟;
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

int N,Root,Ans_K,Level_Max;
int Level[100000];
double P,R,Ans;
vector<int> Tree[100000];

void Input(){
	int i,parent;
	scanf("%d%lf%lf",&N,&P,&R);
	for(i=0;i<N;i++){
		scanf("%d",&parent);
		if(parent>=0)
			Tree[parent].push_back(i);
		else 
			Root=i;
	}
}

void LevelOrder(){
	int i,j,k;
	Ans_K=1;
	Level_Max=0;
	Level[Root]=0;
	queue<int> Q;
	Q.push(Root);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		for(j=0;j<Tree[i].size();j++){
			k=Tree[i][j];
			Level[k]=1+Level[i];
			if(Level[k]>Level_Max){
				Level_Max=Level[k];
				Ans_K=1;
			}
			else if(Level[k]==Level_Max)
				Ans_K++;
			Q.push(k);
		}
	}
	Ans=P*pow(1+R/100,Level_Max);
}

void Process(){
	LevelOrder();
}

void Display(){
	printf("%.2f %d\n",Ans,Ans_K);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
