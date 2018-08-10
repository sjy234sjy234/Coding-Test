#include<iostream>  //测试点有一个很坑的点:输入为1,只有一个结点,直接输出1;
#include<algorithm>  //小技巧,只需要对叶子结点求,叶子结点在图的保存中其相邻结点数为1;
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

int N,C,Max_Level;
int STree[10001],Level[10001];
bool Mark[10001];
vector<int> Graph[10001];
priority_queue<int,vector<int>,greater<int>> Ans;
queue<int> Q;

int Root(int x){
	if(STree[x]==0)
		return x;
	else{
		int temp=Root(STree[x]);
		STree[x]=temp;
		return temp;
	}
}

void Input(){
	int i,c1,c2;
	scanf("%d",&N);
	C=0;
	for(i=1;i<N;i++){
		scanf("%d%d",&c1,&c2);
		Graph[c1].push_back(c2);
		Graph[c2].push_back(c1);
		c1=Root(c1);
		c2=Root(c2);
		if(c1!=c2){
			STree[c2]=c1;
			C++;
		}
	}
}

void BFS(int k){
	int i,j,l,m;
	Mark[k]=true;
	Q.push(k);
	Level[k]=0;
	while(!Q.empty()){
		i=Q.front();
		Q.pop();
		l=Level[i];
		for(j=0;j<Graph[i].size();j++){
			m=Graph[i][j];
			if(!Mark[m]){
				Level[m]=1+l;
				Mark[m]=true;
				Q.push(m);
			}
		}
	}
	if(l>Max_Level){
		Max_Level=l;
		while(!Ans.empty())
			Ans.pop();
		Ans.push(k);
	}
	else if(l==Max_Level)
		Ans.push(k);
}

void Process(){
	if(C==N-1){
		int i,j;
		Max_Level=-1;
		for(i=1;i<=N;i++)
			if(Graph[i].size()==1){
				for(j=1;j<=N;j++)
					Mark[j]=false;
				BFS(i);
			}
	}
	else
		printf("Error: %d components\n",N-C);
}

void Display(){
	if(N==1)
		printf("1\n");
	while(!Ans.empty()){
		printf("%d\n",Ans.top());
		Ans.pop();
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
