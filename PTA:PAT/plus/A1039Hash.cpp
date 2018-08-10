#include<iostream>  //不要吝啬空间,几十万的Q也是可以随便开的;
#include<algorithm>  //利用哈希映射的经典案例;
#include<string.h>  //由于是查询题目,不排除多次查同一个学生,因此采用vector+sort更好;
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
vector<int> Graph[175760];

int GetNum(char s[]){
	int i,p;
	p=0;
	for(i=0;i<3;i++)
		p=p*26+s[i]-'A';
	p=p*10+s[3]-'0';
	return p;
}

void Input(){
	int i,course,n,stu;
	char s[5];
	C=0;
	scanf("%d%d",&N,&K);
	for(i=0;i<K;i++){
		scanf("%d%d",&course,&n);
		while(n-->0){
			scanf("%s",s);
			stu=GetNum(s);
			Graph[stu].push_back(course);
		}
	}
	for(i=0;i<175760;i++)
		if(!Graph[i].empty())
			sort(Graph[i].begin(),Graph[i].end());
}

void Process(){
	int i,stu;
	char s[5];
	while(N-->0){
		scanf("%s",s);
		stu=GetNum(s);
		printf("%s %d",s,Graph[stu].size());
		for(i=0;i<Graph[stu].size();i++)	
			printf(" %d",Graph[stu][i]);
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
