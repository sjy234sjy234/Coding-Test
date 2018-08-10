#include<iostream>  //此处利用了1)先反转简化逻辑;2)求Min_Len统一循环过程;
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

int N,Min_Len,Ans;
char A[100][260];

void Reverse(int k){
	char temp;
	int i,j,l=strlen(A[k]);
	if(l<Min_Len)
		Min_Len=l;
	j=l>>1;
	l--;
	for(i=0;i<j;i++){
		temp=A[k][i];
		A[k][i]=A[k][l-i];
		A[k][l-i]=temp;
	}
}

void Input(){
	int i;
	scanf("%d",&N);
	getchar();
	Min_Len=1000;
	for(i=0;i<N;i++){
		gets(A[i]);
		Reverse(i);
	}
}

void Process(){
	int i,j;
	Ans=-1;
	for(i=0;i<Min_Len;i++){
		for(j=1;j<N&&A[j][i]==A[j-1][i];j++);
		if(j==N)
			Ans=i;
		else
			return;
	}
}

void Display(){
	int i;
	if(Ans<0)
		printf("nai\n");
	else{
		for(i=Ans;i>=0;i--)
			printf("%c",A[0][i]);
		printf("\n");
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