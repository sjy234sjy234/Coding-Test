#include<iostream>  //数据很多时,需要自己建立哈希映射,最后一个案例不能通过;
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

int N,K,C;
map<string,int> MP;
priority_queue<int,vector<int>,greater<int> > Graph[40001];

void Input(){
	int i,course,n,person;
	char s[5];
	scanf("%d%d",&N,&K);
	C=0;
	for(i=0;i<K;i++){
		scanf("%d%d",&course,&n);
		while(n-->0){
			scanf("%s",s);
			person=MP[s];
			if(person==0)
				MP[s]=person=++C;
			Graph[person].push(course);
		}
	}
}

void Process(){
	int person;
	char s[5];
	while(N-->0){
		scanf("%s",s);
		person=MP[s];
		printf("%s %d",s,Graph[person].size());
		while(!Graph[person].empty()){
			printf(" %d",Graph[person].top());
			Graph[person].pop();
		}
		printf("\n");
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
