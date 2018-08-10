#include<iostream>  //当题目给出了数值的范围限制时,一定要学会往Hash思想上靠;
#include<algorithm>  //此处的优点在于虽然coin的范围只有1-500,但是数组开到了1-1000,避免了为防止段错误而做的多余条件判断;
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
int Count[1001];

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
	l=M>>1;
	for(i=1;i<=l;i++){
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