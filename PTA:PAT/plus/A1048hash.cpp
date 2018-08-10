#include<iostream>  //当题目给出了数值的范围限制时,一定要学会往Hash思想上靠;
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

int N,M;
int Count[501];

void Input(){
	int t;
	scanf("%d%d",&N,&M);
	while(N-->0){
		scanf("%d",&t);
		Count[t]++;
	}
}

void Process(){
	int i,l;
	l=M>>1;  //遍历上限M/2,遍历下限max(1,M-500);
	for(i=max(1,M-500);i<=l;i++){
		if(i!=M-i&&Count[i]&&Count[M-i]){  //M=i+(M-i)且i!=M-i的情况;
			printf("%d %d\n",i,M-i);
			return;
		}
		else if(i==M-i&&Count[i]>1){  //必须考虑M%2==0且刚好M=M/2+M/2的情况;
			printf("%d %d\n",i,i);
			return;
		}
	}		
	printf("No Solution\n");  //上述条件都不通过,说明不存在答案;
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