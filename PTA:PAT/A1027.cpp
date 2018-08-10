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

int Color[3];
char Refer[14]="0123456789ABC";

void Input(){
	scanf("%d%d%d",&Color[0],&Color[1],&Color[2]);
	printf("#");
}

void Process(){
	int high,low;
	for(int i=0;i<3;i++){
		low=Color[i]%13;
		high=Color[i]/13;
		printf("%c%c",Refer[high],Refer[low]);
	}
}

void Display(){
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