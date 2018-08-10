#include<iostream>  //有些题目的输入项目,不得不使用cin;
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

int Max_A,Max_B;
int N,Record_A[3],Record_B[3],Count_A[3],Count_B[3];
char A,B;
char Refer[4]="BCJ";

void cmp(char &a,char &b){
	if(a==b){
		Record_A[1]++;
		Record_B[1]++;
	}
	else if(a=='B'){
		if(b=='C'){
			Record_A[0]++;
			Record_B[2]++;
			Count_A[0]++;
		}
		else{
			Record_A[2]++;
			Record_B[0]++;
			Count_B[2]++;
		}
	}
	else if(a=='C'){
		if(b=='B'){
			Record_A[2]++;
			Record_B[0]++;
			Count_B[0]++;
		}
		else{
			Record_A[0]++;
			Record_B[2]++;
			Count_A[1]++;
		}
	}
	else{
		if(b=='B'){
			Record_A[0]++;
			Record_B[2]++;
			Count_A[2]++;
		}
		else{
			Record_A[2]++;
			Record_B[0]++;
			Count_B[1]++;
		}
	}
}

void Input(){
	int i;
	for(i=0;i<3;i++)
		Record_A[i]=Record_B[i]=Count_A[i]=Count_B[i]=0;
	scanf("%d",&N);
}

void Process(){
	int i;
	for(i=0;i<N;i++){
		cin>>A>>B;
		cmp(A,B);
	}
	Max_A=Max_B=0;
	for(i=1;i<3;i++){
		if(Count_A[i]>Count_A[Max_A])
			Max_A=i;
		if(Count_B[i]>Count_B[Max_B])
			Max_B=i;
	}
}

void Display(){
	printf("%d %d %d\n",Record_A[0],Record_A[1],Record_A[2]);
	printf("%d %d %d\n",Record_B[0],Record_B[1],Record_B[2]);
	printf("%c %c\n",Refer[Max_A],Refer[Max_B]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}