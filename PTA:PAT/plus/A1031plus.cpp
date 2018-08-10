#include<iostream>  //简单模拟画图;
#include<algorithm>  //经常出现的思想,对画图因子的H和W的大小有所要求,需要遍历和计算求解;
#include<string.h>  //此题更好的求解N1,N2的方法是N1=[(L+2)/3],即向下取整;
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int L,N1,N2;
char A[100];

void GetN(){  //这个是经过分析得出的方法,比遍历方法要好;
	N1=(L+2)/3;
	N2=L+2-2*N1;
}

void Input(){
	scanf("%s",A);
	L=strlen(A);
	GetN();
}

void Process(){
	int i,j;
	for(i=0;i<N1-1;i++){
		printf("%c",A[i]);
		for(j=2;j<N2;j++)
			printf(" ");
		printf("%c\n",A[L-1-i]);
	}
	for(;i<N1+N2-1;i++)
		printf("%c",A[i]);
	printf("\n");
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