#include<iostream>  //自己实现的过程总是效率高更多;
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
using namespace std;

int N,M,K;
int Num[51][10000];
int Count[51];

void Input(){
	int i,j,n,t;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&n);
		for(j=0;j<n;j++)
			scanf("%d",&Num[i][j]);
		sort(Num[i],Num[i]+n);
		t=1;
		for(j=1;j<n;j++)
			if(Num[i][j]!=Num[i][j-1])
				Num[i][t++]=Num[i][j];
		Count[i]=t;
	}
}

void Process(){
	int i,j,c1,c2,c,r1,r2;
	scanf("%d",&K);
	while(K-->0){
		scanf("%d%d",&r1,&r2);
		c1=Count[r1];
		c2=Count[r2];
		i=j=c=0;
		while(i<c1&&j<c2){
			if(Num[r1][i]==Num[r2][j]){
				i++;
				j++;
				c++;
			}
			else if(Num[r1][i]<Num[r2][j]){
				i++;
				c++;
			}
			else{
				j++;
				c++;
			}
		}
		if(i<c1)
			c+=c1-i;
		if(j<c2)
			c+=c2-j;
		printf("%.1f%%\n",(double)(c1+c2-c)/c*100);
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
