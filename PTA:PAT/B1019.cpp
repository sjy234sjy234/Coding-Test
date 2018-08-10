#include<iostream>  //priority_queue的灵活应用;
#include<algorithm>  //有一个输入是6174的情况,也需要输出一个步骤;
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int N;
priority_queue<int> Q1;
priority_queue<int,vector<int>,greater<int>> Q2;

void Input(){
	scanf("%d",&N);
}

void Process(){
	if(N%1111==0)
		printf("%04d - %04d = %04d\n",N,N,0);
	else if(N==6174)
		printf("7641 - 1467 = 6174\n");
	else{
		int n1,n2,i,t;
		while(N!=6174){
			for(i=0;i<4;i++){
				t=N%10;
				Q1.push(t);
				Q2.push(t);
				N/=10;
			}
			n1=n2=0;
			while(!Q1.empty()){
				n1=n1*10+Q1.top();
				Q1.pop();
			}
			while(!Q2.empty()){
				n2=n2*10+Q2.top();
				Q2.pop();
			}
			N=n1-n2;
			printf("%04d - %04d = %04d\n",n1,n2,N);
		}
	}
}

void Display(){

}

int main(){
//	while(true){
	Input();
	Process();
//	Display();
//	}
	return 0;
}