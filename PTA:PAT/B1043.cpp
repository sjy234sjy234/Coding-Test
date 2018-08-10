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

char Refer[7]="PATest";
char A[10050];
int Count[6];
bool Flag;

void Input(){
	scanf("%s",A);
}

void Process(){
	int i;
	for(i=0;i<6;i++)
		Count[i]=0;
	for(i=0;A[i]!='\0';i++){
		switch(A[i]){
		case 'P':Count[0]++;break;
		case 'A':Count[1]++;break;
		case 'T':Count[2]++;break;
		case 'e':Count[3]++;break;
		case 's':Count[4]++;break;
		case 't':Count[5]++;
		}
	}
}

void Display(){
	int i;
	Flag=true;
	while(Flag){
		Flag=false;
		for(i=0;i<6;i++){
			if(Count[i]){
				printf("%c",Refer[i]);
				Count[i]--;
				if(Count[i])
					Flag=true;
			}
		}
	}
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