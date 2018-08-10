#include<iostream>  //此处是有向图,弄清楚方向;
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

int N,L,K;
int Level[1001];
bool Mark[1001];
vector<int> Graph[1001];
queue<int> Q;

void Input(){
	int i,parent;
	scanf("%d%d",&N,&L);
	for(i=1;i<=N;i++){
		scanf("%d",&K);
		while(K-->0){
			scanf("%d",&parent);
			Graph[parent].push_back(i);
		}
	}
}

int LevelOrder(int q){
	int i,j,k,l,c;
	c=0;
	Level[q]=0;
	while(!Q.empty())
		Q.pop();
	Q.push(q);
	Mark[q]=true;
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		l=Level[i]+1;
		if(l>L)
			return c;
		else{
			for(j=0;j<Graph[i].size();j++){
				k=Graph[i][j];
				if(!Mark[k]){
					Mark[k]=true;
					Level[k]=l;
					c++;
					Q.push(k);
				}
			}
		}
	}
	return c;
}

void Process(){
	int query;
	scanf("%d",&K);
	while(K-->0){
		scanf("%d",&query);
		for(int i=1;i<=N;i++)
			Mark[i]=false;
		printf("%d\n",LevelOrder(query));
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
