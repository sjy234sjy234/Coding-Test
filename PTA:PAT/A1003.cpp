#include<iostream>  //十分注意,min_pos和i极其容易写错;
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
int N,M,Sta,End;
int Team[500],Dist[500],Num[500],Gather[500];
bool Mark[500];
vector<linknode> Graph[500];

void Input(){
	int i,c1,c2,dist;
	scanf("%d%d%d%d",&N,&M,&Sta,&End);
	for(i=0;i<N;i++){
		scanf("%d",&Team[i]);
		Dist[i]=INF;
	}
	for(i=0;i<M;i++){
		scanf("%d%d%d",&c1,&c2,&dist);
		Temp.dist=dist;
		Temp.next=c2;
		Graph[c1].push_back(Temp);
		Temp.next=c1;
		Graph[c2].push_back(Temp);
	}
}

void Process(){
	int i,j,k,min_pos,dist;
	Dist[Sta]=0;
	Num[Sta]=1;
	Gather[Sta]=Team[Sta];
	for(i=0;i<N;i++){
		min_pos=-1;
		for(j=0;j<N;j++){
			if(!Mark[j]){
				if(min_pos==-1)
					min_pos=j;
				else if(Dist[j]<Dist[min_pos])
					min_pos=j;
			}
		}
		Mark[min_pos]=true;
		if(min_pos==End||Dist[min_pos]>=INF)
			return;
		for(j=0;j<Graph[min_pos].size();j++){  //此处很容易把min_pos写成i,要十分小心;
			k=Graph[min_pos][j].next;
			dist=Graph[min_pos][j].dist;
			if(!Mark[k]){
				if(dist+Dist[min_pos]<Dist[k]){
					Dist[k]=dist+Dist[min_pos];
					Num[k]=Num[min_pos];
					Gather[k]=Gather[min_pos]+Team[k];
				}
				else if(dist+Dist[min_pos]==Dist[k]){
					Num[k]+=Num[min_pos];
					if(Gather[min_pos]+Team[k]>Gather[k])
						Gather[k]=Gather[min_pos]+Team[k];
				}
			}
		}
	}
}

void Display(){
	printf("%d %d\n",Num[End],Gather[End]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
