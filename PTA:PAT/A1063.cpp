#include<iostream>  //本题涉及了set的简单应用,以及集合的交并情况;
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

int N,M,K;
set<int> S[51];
set<int>::iterator It_1,It_2;

void Input(){
	int i,temp;
	scanf("%d",&N);
	for(i=1;i<=N;i++){
		scanf("%d",&M);
		while(M-->0){
			scanf("%d",&temp);
			S[i].insert(temp);
		}
	}
}

void Process(){
	int r1,r2,c1,c2,c,k1,k2;
	scanf("%d",&K);
	while(K-->0){
		S[0].clear();
		scanf("%d%d",&r1,&r2);
		c1=S[r1].size();
		c2=S[r2].size();
		It_1=S[r1].begin();
		It_2=S[r2].begin();
		k1=k2=c=0;
		while(k1<c1&&k2<c2){  //只对集合做查询,效率还是很高的;
			if(*It_1==*It_2){
				It_1++;
				It_2++;
				k1++;
				k2++;
				c++;
			}
			else if(*It_1<*It_2){
				k1++;
				It_1++;
				c++;
			}
			else{
				k2++;
				It_2++;
				c++;
			}
		}
		if(k1<c1)
			c+=c1-k1;
		if(k2<c2)
			c+=c2-k2;
		printf("%.1f%%\n",(double)(c1+c2-c)/c*100);
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
