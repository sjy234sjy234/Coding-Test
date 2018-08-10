#include<iostream>  //并查集的简单应用,需要使用num域记录集合个数,以及利用优先队列记录结果以按序输出;
#include<algorithm>  //在应试中利用STL容器的不同功能来记录结果是一种非常好的做法;
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
	int num,parent;
	bool operator<(const node &b)const{
		return num<b.num;
	}
}Tree[1010];

int N,K;
vector<int> Hobby[1001];
priority_queue<node> Q;

void Input(){
	int i,h;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d:",&K);
		while(K-->0){
			scanf("%d",&h);
			Hobby[h].push_back(i);
		}
		Tree[i].num=1;
	}
}

int GetRoot(int x){
	if(Tree[x].parent==0)
		return x;
	else{
		int temp=GetRoot(Tree[x].parent);
		Tree[x].parent=temp;
		return temp;
	}
}

void Process(){
	int i,j,k,l,c1,c2;
	for(i=1;i<=1000;i++){
		l=Hobby[i].size();
		for(j=0;j<l-1;j++){
			c1=Hobby[i][j];
			c1=GetRoot(c1);
			for(k=j+1;k<l;k++){
				c2=Hobby[i][k];
				c2=GetRoot(c2);
				if(c2!=c1){
					Tree[c2].parent=c1;
					Tree[c1].num+=Tree[c2].num;
				}
			}
		}
	}
	for(i=1;i<=N;i++)
		if(Tree[i].parent==0)
			Q.push(Tree[i]);
}

void Display(){
	printf("%d\n",Q.size());
	while(Q.size()>1){
		printf("%d ",Q.top().num);
		Q.pop();
	}
	printf("%d\n",Q.top().num);
	Q.pop();
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
