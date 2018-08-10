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

struct linknode{
	int next,dist;
}Temp;

const int INF=1000000000;
int N,M,Cp,End,Sta;
int Bike[501],Dist[501];
bool Mark[501];
vector<linknode> Graph_0[501];
vector<int> Graph_r[501];
vector<int> Ans,Ans_Temp;

void Input(){
	int i,c1,c2,dist;
	Sta=0;
	scanf("%d%d%d%d",&Cp,&N,&End,&M);
	Dist[0]=INF;
	for(i=1;i<=N;i++){
		scanf("%d",&Bike[i]);
		Dist[i]=INF;
	}
	for(i=0;i<M;i++){
		scanf("%d%d%d",&c1,&c2,&dist);
		Temp.dist=dist;
		Temp.next=c2;
		Graph_0[c1].push_back(Temp);
		Temp.next=c1;
		Graph_0[c2].push_back(Temp);
	}
}

void Dijkstra(){
	int i,j,k,min_pos,dist;
	Dist[End]=0;
	for(i=0;i<=N;i++){
		min_pos=-1;
		for(j=0;j<=N;j++){
			if(!Mark[j]){
				if(min_pos==-1)
					min_pos=j;
				else if(Dist[j]<Dist[min_pos])
					min_pos=j;
			}
		}
		Mark[min_pos]=true;
		if(min_pos==Sta||Dist[min_pos]>=INF)
			break;
		for(j=0;j<Graph_0[min_pos].size();j++){
			k=Graph_0[min_pos][j].next;
			dist=Graph_0[min_pos][j].dist;
			if(!Mark[k]){
				if(dist+Dist[min_pos]<Dist[k]){
					Dist[k]=dist+Dist[min_pos];
					Graph_r[k].clear();
					Graph_r[k].push_back(min_pos);
				}
				else if(dist+Dist[min_pos]==Dist[k])
					Graph_r[k].push_back(min_pos);
			}
		}
	}
}

void DFS(int k,int s){

}

void Process(){
	Dijkstra();
	DFS(0,0);
}

void Display(){

}

int main(){
	while(true){
	Input();
	Process();
	Display();
	}
	return 0;
}
