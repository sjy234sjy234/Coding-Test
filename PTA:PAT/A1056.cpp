#include<iostream>  //两个很坑的点,1)rank的规则没说;2)给出的weight按序号递增,第二行给出的是玩游戏顺序,需要利用哈希思想;
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

struct player{
	int num,weight;
	bool operator<(const player &b)const{
		return weight>b.weight;
	}
}Temp;

int Weight[1000],Order[1000],Rank[1000];
int Np,Ng;
queue<player> Q;
priority_queue<player> Op;  

void Input(){
	int i;
	scanf("%d%d",&Np,&Ng);
	for(i=0;i<Np;i++)
		scanf("%d",&Weight[i]);
	for(i=0;i<Np;i++)
		scanf("%d",&Order[i]);
	for(i=0;i<Np;i++){
		Temp.num=Order[i];
		Temp.weight=Weight[Order[i]];
		Q.push(Temp);
	}
}

void Process(){
	int i,j,n,q;
	n=Np;
	while(n!=1){
		if(n%Ng)
			q=n/Ng+1;
		else
			q=n/Ng;
		i=0;
		while(i<n){		
			for(j=0;j<Ng&&i<n;i++,j++){		
				Temp=Q.front();			
				Q.pop();			
				Op.push(Temp);		
			}		
			while(j-->1){			
				Temp=Op.top();			
				Op.pop();			
				Rank[Temp.num]=q+1;		
			}
			Q.push(Op.top());
			Op.pop();
		}
		n=q;
	}
	Temp=Q.front();
	Q.pop();
	Rank[Temp.num]=1;
}

void Display(){
	printf("%d",Rank[0]);
	for(int i=1;i<Np;i++)
		printf(" %d",Rank[i]);
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
