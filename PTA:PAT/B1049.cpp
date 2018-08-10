#include<iostream>  //左右两端两点思想;
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

int N;
double S;

void Input(){
	int i;
	double temp;
	S=0;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%lf",&temp);
		S+=temp*i*(N-i+1);
	}
}

void Process(){

}

void Display(){
	printf("%.2f\n",S);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}