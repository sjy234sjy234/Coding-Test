#include<iostream>
#include<algorithm>
#include<string.h>
#include<ctype.h>  //可以用+-动态法,哈希法,map法;
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

int M,N,C;
long long Temp,Rec;

void Input(){
	int i,j;
	C=0;
	Rec=-1;
	scanf("%d%d",&M,&N);
	for(i=0;i<M;i++)
		for(j=0;j<N;j++){
			scanf("%lld",&Temp);
			if(Temp==Rec)
				C++;
			else{
				if(C==0){
					Rec=Temp;
					C=1;
				}
				else
					C--;
			}
		}
}

void Process(){

}

void Display(){
	printf("%lld\n",Rec);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
