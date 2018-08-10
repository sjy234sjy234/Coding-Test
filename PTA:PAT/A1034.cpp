#include<iostream>  //并查集的综合应用,关键是要理清楚关系,以及分清楚node和linknode之间的联系和区别;
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
#include<set>
using namespace std;

struct node{
	int num,weight,parent,cum;
}Tree[17576];

struct linknode{
	int c1,c2,weight;
}Temp;

int N,K;
vector<linknode> Relation;
queue<int> Ans;

int GetNum(char name[]){
	int s=0;
	for(int i=0;i<3;i++)
		s=s*26+name[i]-'A';
	return s;
}

void Input(){
	int i,weight,c1,c2;
	char name1[4],name2[4];
	scanf("%d%d",&N,&K);
	for(i=0;i<17576;i++){
		Tree[i].num=1;
		Tree[i].parent=-1;
	}
	for(i=0;i<N;i++){
		scanf("%s%s%d",name1,name2,&weight);
		c1=GetNum(name1);
		c2=GetNum(name2);
		Temp.c1=c1;
		Temp.c2=c2;
		Temp.weight=weight;
		Relation.push_back(Temp);
		Tree[c1].weight+=weight;
		Tree[c2].weight+=weight;
	}
}

int GetRoot(int x){
	if(Tree[x].parent==-1)
		return x;
	else{
		int temp=GetRoot(Tree[x].parent);
		Tree[x].parent=temp;
		return temp;
	}
}

void Process(){
	int i,c1,c2,weight;
	for(i=0;i<Relation.size();i++){
		c1=Relation[i].c1;
		c2=Relation[i].c2;
		weight=Relation[i].weight;
		c1=GetRoot(c1);
		c2=GetRoot(c2);
		if(c1==c2)
			Tree[c1].cum+=weight;
		else{
			if(Tree[c1].weight>Tree[c2].weight){
				Tree[c2].parent=c1;
				Tree[c1].num+=Tree[c2].num;
				Tree[c1].cum+=Tree[c2].cum;
				Tree[c1].cum+=weight;
			}
			else{
				Tree[c1].parent=c2;
				Tree[c2].num+=Tree[c1].num;
				Tree[c2].cum+=Tree[c1].cum;
				Tree[c2].cum+=weight;
			}
		}
	}
	for(i=0;i<17576;i++)
		if(Tree[i].parent==-1&&Tree[i].num>2&&Tree[i].cum>K)
			Ans.push(i);
}

void Print(int k){
	int i,t;
	char s[4];
	s[3]='\0';
	for(i=2,t=k;i>=0;i--){
		s[i]=t%26+'A';
		t/=26;
	}
	printf("%s %d\n",s,Tree[k].num);
}

void Display(){
	int i;
	printf("%d\n",Ans.size());
	while(!Ans.empty()){
		i=Ans.front();
		Ans.pop();
		Print(i);
	}
}

int main(){
	while(true){
	Input();
	Process();
	Display();
	}
	return 0;
}
