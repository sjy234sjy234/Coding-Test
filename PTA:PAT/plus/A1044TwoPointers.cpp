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
#include<map>
using namespace std;

struct node{
	int i,j;
}Temp;

const long long INF=10000000000000000LL;
int N;
long long Min_Sum,M,A[100000];
queue<node> Ans;

void Input(){
	int i;
	scanf("%d%lld",&N,&M);
	for(i=0;i<N;i++)
		scanf("%lld",&A[i]);
}

void Process(){
	int i,j;
	long long s;
	i=j=0;
	s=A[0];
	Min_Sum=INF;
	while(i<N&&j<N){
		if(s<M){
			j++;
			if(j==N)
				break;
			s+=A[j];
		}
		else {		
			if(s<Min_Sum){			
				while(!Ans.empty())				
					Ans.pop();			
				Temp.i=i+1;			
				Temp.j=j+1;			
				Ans.push(Temp);			
				Min_Sum=s;		
			}
			else if(s==Min_Sum){
				Temp.i=i+1;			
				Temp.j=j+1;			
				Ans.push(Temp);	
			}
			if(i==j){
				i++;
				j++;
				if(j==N)
					break;
				s=A[j];
			}
			else{
				s-=A[i];
				i++;			
			}
		}
	}
}

void Display(){
	while(!Ans.empty()){
		Temp=Ans.front();
		Ans.pop();
		printf("%d-%d\n",Temp.i,Temp.j);
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
