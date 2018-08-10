#include<iostream>
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

int N,A1,A2,A3,A5,C4;
double A4;
bool Flag2;

void Input(){
	int i,temp,flag=1;
	A4=A1=A2=A3=A5=0;
	Flag2=false;
	C4=0;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%d",&temp);
		switch(temp%5){
		case 0:
			if(temp%2==0)
				A1+=temp;
			break;

		case 1:
			Flag2=true;
			A2+=temp*flag;
			flag=-flag;
			break;

		case 2:
			A3++;
			break;

		case 3:
			A4+=temp;
			C4++;
			break;

		case 4:
			if(temp>A5)
				A5=temp;

		}
	}
	if(C4)
		A4/=C4;
}

void Process(){

}

void Display(){
	if(A1)
		printf("%d ",A1);
	else
		printf("N ");
	if(Flag2)
		printf("%d ",A2);
	else
		printf("N ");
	if(A3)
		printf("%d ",A3);
	else
		printf("N ");
	if(C4)
		printf("%.1f ",A4);
	else
		printf("N ");
	if(A5)
		printf("%d\n",A5);
	else
		printf("N\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}