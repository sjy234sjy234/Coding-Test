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

int N;
int Weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char Refer[12]="10X98765432";
char ID[100][19];
queue<int> Q;


bool Legal(int k){
	int s=0;
	for(int i=0;i<17;i++){
		if(ID[k][i]>'9'||ID[k][i]<'0')
			return false;
		else
			s+=(ID[k][i]-'0')*Weight[i];
	}
	s%=11;
	if(Refer[s]==ID[k][17])
		return true;
	else
		return false;
}

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",ID[i]);
		if(!Legal(i))
			Q.push(i);
	}
}

void Process(){

}

void Display(){
	if(Q.empty())
		printf("All passed\n");
	else{
		while(!Q.empty()){
			printf("%s\n",ID[Q.front()]);
			Q.pop();
		}
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