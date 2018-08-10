#include<iostream>  //map的效率还是很高的;
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

int M,N,C;
long long Temp,Rec;
map<long long,int> MP;

void Input(){
	int i,j,t;
	scanf("%d%d",&M,&N);
	for(i=0;i<M;i++)
		for(j=0;j<N;j++){
			scanf("%lld",&Temp);
			t=++MP[Temp];
			if(t>C){
				C=t;
				Rec=Temp;
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
