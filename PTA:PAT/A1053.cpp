#include<iostream>  //深度优先搜索,vector内排序,对答案有顺序大小的要求,其实与1103非常类似,只是变量条件略少一些;
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

struct node{
	long long weight;
	int next;
	bool operator<(const node &b)const{
		return weight>b.weight;
	}
}Temp;

int N,M,K;
long long Weight[101];
long long S;
vector<node> Tree[101];
vector<long long> Ans;

void Input(){
	int i,parent,son;
	scanf("%d%d%lld",&N,&M,&S);
	for(int i=0;i<N;i++)
		scanf("%lld",&Weight[i]);
	while(M-->0){
		scanf("%d%d",&parent,&K);
		while(K-->0){
			scanf("%d",&son);
			Temp.next=son;
			Temp.weight=Weight[son];
			Tree[parent].push_back(Temp);
		}
	}
	for(i=0;i<N;i++)
		if(!Tree[i].empty())
			sort(Tree[i].begin(),Tree[i].end());
}

void Print(){
	printf("%lld",Ans[0]);
	for(int i=1;i<Ans.size();i++)
		printf(" %lld",Ans[i]);
	printf("\n");
}

void DFS(int i,long long s){
	if(s==S&&Tree[i].empty())
		Print();
	else if(s>S||Tree[i].empty())
		return;
	else{
		int j,k;
		for(j=0;j<Tree[i].size();j++){
			k=Tree[i][j].next;
			Ans.push_back(Weight[k]);
			DFS(k,s+Weight[k]);
			Ans.pop_back();
		}
	}
}

void Process(){
	Ans.push_back(Weight[0]);
	DFS(0,Weight[0]);
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
