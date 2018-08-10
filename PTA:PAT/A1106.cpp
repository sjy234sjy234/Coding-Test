#include<iostream>  //似乎只要考到了树,都是BFS();
#include<algorithm>  //此题有个小技巧,就是借助了queue<int> Q存放所有的叶子结点,避免了无谓的暴力搜索;
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

const int INF=1000000000;
int N,K,Min_Level,Ans_K;
double P,R,Ans;
int Level[100000];
vector<int> Tree[100000];
vector<int> Retailer;

void Input(){
	int i,son;
	scanf("%d%lf%lf",&N,&P,&R);
	for(i=0;i<N;i++){
		scanf("%d",&K);
		if(K==0)
			Retailer.push_back(i);
		else{
			while(K-->0){
				scanf("%d",&son);
				Tree[i].push_back(son);
			}
		}
	}
}

void Process(){
	int i,j,k,l;
	Level[0]=0;
	queue<int> Q;
	Q.push(0);
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		for(j=0;j<Tree[i].size();j++){
			k=Tree[i][j];
			Level[k]=1+Level[i];
			Q.push(k);
		}
	}
	Min_Level=INF;
	for(i=0;i<Retailer.size();i++){
		k=Retailer[i];
		l=Level[k];
		if(l<Min_Level){
			Min_Level=l;
			Ans_K=1;
		}
		else if(l==Min_Level)
			Ans_K++;
	}
	Ans=P*pow(1+R/100,Min_Level);
}

void Display(){
	printf("%.4f %d\n",Ans,Ans_K);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
