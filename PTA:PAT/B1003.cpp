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

int N,Ans[10],Count[3];
char Str[101];
char Refer[2][4]={"YES","NO"};

int GetAns(){
	int i,i_p,i_t;
	i_p=i_t=-1;
	for(i=0;i<3;i++)
		Count[i]=0;
	for(i=0;Str[i]!='\0';i++){
		switch(Str[i]){

		case 'P':
			Count[0]++;
			if(Count[0]>1)
				return 1;
			i_p=i;
			break;

		case 'A':
			Count[1]++;
			break;
				 
		case 'T':
			Count[2]++;
			if(Count[2]>1)
				return 1;
			i_t=i;
			break;
				 
		default:
			return 1;
		}
	}

	if(i_t==-1||i_p==-1)
		return 1;
	else{
		if((i_t-i_p-1)!=0&&(i_t-i_p-1)*i_p==i-i_t-1)
			return 0;
		else
			return 1;
	}
}

void Input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%s",Str);
		Ans[i]=GetAns();
	}
}

void Process(){
	for(int i=0;i<N;i++)
		printf("%s\n",Refer[Ans[i]]);
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