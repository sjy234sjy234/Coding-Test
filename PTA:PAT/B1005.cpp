#include<iostream>  //无论如何都不要使用复制,要使用手动输入;
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int K,A[100];
bool Mark[101];

bool cmp(const int &a,const int &b){
	return a>b;
}

void Input(){
	int i;
	for(i=0;i<101;i++)
		Mark[i]=false;
	scanf("%d",&K);
	for(i=0;i<K;i++)
		scanf("%d",&A[i]);
	sort(A,A+K,cmp);
}

void Deal(int x){
	if(Mark[x])
		return;
	if(x%2)
		x=(3*x+1)/2;
	else
		x/=2;
	while(x!=1){
		if(x<=100){		
			if(Mark[x])			
				return;
			Mark[x]=true;
		}
		if(x%2)
			x=(3*x+1)/2;
		else
			x/=2;
	}
}

void Process(){
	for(int i=0;i<K;i++)
		Deal(A[i]);
}

void Display(){
	int i;
	for(i=0;i<K;i++)
		if(!Mark[A[i]]){
			printf("%d",A[i]);
			break;
		}
	for(i++;i<K;i++)
		if(!Mark[A[i]])
			printf(" %d",A[i]);
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