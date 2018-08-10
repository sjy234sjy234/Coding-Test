#include<iostream>  //简单模拟,找每一行的最大值;
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

int Max[3];
char Refer[4]="WTL";
double Data[3][3],Ans;

void Input(){
	int i,j;
	for(i=0;i<3;i++){
		Max[i]=0;
		for(j=0;j<3;j++){
			scanf("%lf",&Data[i][j]);
			if(Data[i][j]>Data[i][Max[i]])
				Max[i]=j;
		}
	}
}

void Process(){
	Ans=(Data[0][Max[0]]*Data[1][Max[1]]*Data[2][Max[2]]*0.65-1)*2;
}

void Display(){
	for(int i=0;i<3;i++)
		printf("%c ",Refer[Max[i]]);
	printf("%.2f\n",Ans);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}