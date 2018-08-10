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

int Na,Nb;
long long A[100000],B[100000];
long long S;

void Input(){
	int i;
	scanf("%d",&Na);
	for(i=0;i<Na;i++)
		scanf("%lld",&A[i]);
	sort(A,A+Na);
	scanf("%d",&Nb);
	for(i=0;i<Nb;i++)
		scanf("%lld",&B[i]);
	sort(B,B+Nb);
}

void Process(){
	int i,j;

	i=S=0;
	while(i<Na&&i<Nb&&A[i]<0&&B[i]<0)
		S+=A[i]*B[i++];

	i=Na-1;j=Nb-1;	
	while(i>=0&&j>=0&&A[i]>0&&B[j]>0)
		S+=A[i--]*B[j--];
}

void Display(){
	printf("%lld\n",S);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}