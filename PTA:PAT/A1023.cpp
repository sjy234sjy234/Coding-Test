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
#include<stdlib.h>
#include<time.h>
#include<map>
using namespace std;

struct bignum{  //注意DA是A的2倍,因此倍乘以后可能多一位;
	int data[21];
	int num;
}A,DA;

bool Flag;
char S[21];
int L,CountA[10],CountD[10];

void Input(){
	scanf("%s",S);
	L=strlen(S);
}

void GetA(){
	int i;
	for(i=L-1;i>=0;i--)
		A.data[L-1-i]=S[i]-'0';
	A.num=L;
}

void GetDA(){
	int i,temp=0;
	for(i=0;i<A.num;i++){
		temp=temp+A.data[i]*2;
		DA.data[i]=temp%10;
		temp/=10;
	}
	DA.num=A.num;
	if(temp){
		DA.data[i]=temp;
		DA.num++;
	}
}

void Process(){
	int i;
	GetA();
	GetDA();
	if(A.num!=DA.num)
		Flag=false;
	else{
		for(i=0;i<L;i++){
			CountA[A.data[i]]++;
			CountD[DA.data[i]]++;
		}
		for(i=0;i<10&&CountA[i]==CountD[i];i++);
		if(i==10)
			Flag=true;
		else
			Flag=false;
	}
}

void Display(){
	if(Flag)
		printf("Yes\n");
	else
		printf("No\n");
	for(int i=DA.num-1;i>=0;i--)
		printf("%d",DA.data[i]);
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
