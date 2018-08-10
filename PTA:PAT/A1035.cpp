#include<iostream>  //注意细节,单复数的处理;
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

struct student{
	char name[15],password[15];
}Data[1000];

int N;
queue<int> Q;

void Input(){
	int i,j;
	bool flag;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		flag=false;
		scanf("%s %s",Data[i].name,Data[i].password);
		for(j=0;Data[i].password[j]!='\0';j++){
			switch(Data[i].password[j]){
			case '1':Data[i].password[j]='@';flag=true;break;
			case '0':Data[i].password[j]='%';flag=true;break;
			case 'l':Data[i].password[j]='L';flag=true;break;
			case 'O':Data[i].password[j]='o';flag=true;
			}
		}
		if(flag)
			Q.push(i);
	}
}

void Process(){

}

void Display(){
	int i;
	if(Q.empty()){
		if(N==1)		
			printf("There is 1 account and no account is modified\n");		
		else
			printf("There are %d accounts and no account is modified\n",N);
	}
	else{
		printf("%d\n",Q.size());
		while(!Q.empty()){
			i=Q.front();		
			Q.pop();
			printf("%s %s\n",Data[i].name,Data[i].password);
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