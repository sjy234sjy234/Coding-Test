#include<iostream>  //简单的树的层序遍历过程;
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

int N,K,Level[100000];
double P,R,Ans;
double Amount[100000];
vector<int> Tree[100000];

void Input(){
	int i,son;
	scanf("%d%lf%lf",&N,&P,&R);
	for(i=0;i<N;i++){
		scanf("%d",&K);
		if(K==0)
			scanf("%lf",&Amount[i]);
		else{		
			while(K-->0){			
				scanf("%d",&son);
				Tree[i].push_back(son);
			}
		}
	}
}

void LevelOrder(){
	int i,j,k;
	Ans=0;
	Level[0]=0;
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		if(Tree[i].empty())
			Ans+=P*pow(1+R/100,Level[i])*Amount[i];
		for(j=0;j<Tree[i].size();j++){
			k=Tree[i][j];
			Level[k]=1+Level[i];
			Q.push(k);
		}
	}
}

void Process(){
	LevelOrder();
}

void Display(){
	printf("%.1f\n",Ans);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
