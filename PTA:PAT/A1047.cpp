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

int N,K;
priority_queue<int,vector<int>,greater<int> > Graph[2510];

int GetNum(char s[]){
	int i,p;
	p=0;
	for(i=0;i<3;i++)
		p=p*26+s[i]-'A';
	p=p*10+s[3]-'0';
	return p;
}

void Input(){
	int i,stu,course,n;
	char s[5];
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%s%d",s,&n);
		stu=GetNum(s);
		while(n-->0){
			scanf("%d",&course);
			Graph[course].push(stu);
		}
	}
}

void Print(int n){
	char t[5];
	t[4]='\0';
	t[3]=n%10+'0';
	n/=10;
	for(int i=2;i>=0;i--){
		t[i]=n%26+'A';
		n/=26;
	}
	printf("%s\n",t);
}

void Process(){
	int i,stu;
	for(i=1;i<=K;i++){
		printf("%d %d\n",i,Graph[i].size());
		while(!Graph[i].empty()){
			Print(Graph[i].top());
			Graph[i].pop();
		}
	}
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
