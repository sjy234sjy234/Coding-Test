#include<iostream>  //纯粹的考察map的应用,因为任何项目的查找最后都归结到map的映射中去了;
#include<algorithm>  //应该建立不同的映射,虽然答案过了,但是如果不同项目之间有相同的词出现就会出现问题;
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

int N,M,K,Num;
char Temp[81];
map<string,int> MP;
vector<int> Ans[100000];

void Input(){
	int i,t;
	scanf("%d",&N);
	getchar();
	K=0;
	for(i=0;i<N;i++){
		scanf("%d",&Num);  //书号;
		getchar();

		gets(Temp);  //书名;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);

		gets(Temp);  //作者;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);

		while(true){  //关键字;
			scanf("%s",Temp);
			t=MP[Temp];		
			if(t==0)			
				t=MP[Temp]=++K;		
			Ans[t].push_back(Num);
			if(getchar()=='\n')
				break;
		}

		gets(Temp);  //出版社;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);

		gets(Temp);  //出版年份;
		t=MP[Temp];
		if(t==0)
			t=MP[Temp]=++K;
		Ans[t].push_back(Num);
	}
	for(i=1;i<=K;i++)
		sort(Ans[i].begin(),Ans[i].end());
}

void Process(){
	int i,j;
	char s[88];
	scanf("%d",&M);
	getchar();
	while(M-->0){
		gets(s);
		printf("%s\n",s);
		strcpy(Temp,s+3);
		i=MP[Temp];
		if(i==0)
			printf("Not Found\n");
		else{
			for(j=0;j<Ans[i].size();j++)
				printf("%07d\n",Ans[i][j]);
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
