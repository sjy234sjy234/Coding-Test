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
#include<set>
using namespace std;

bool Flag;
int M,N,K;
int A[1000];
stack<int> S;

void Input(){
	scanf("%d%d%d",&M,&N,&K);
}

void Judge(){
	while(!S.empty())
		S.pop();
	int i,j,k;
	i=0;
	j=1;
	while(i<N){
		if(S.empty()||S.top()!=A[i]){  //空或者栈顶不匹配,进栈;
			for(;j<=A[i];j++){
				S.push(j);
				if(S.size()>M){  //栈容量超出,直接失败处理;
					Flag=false;
					return;
				}
			}
		}
		if(S.empty()||S.top()!=A[i]){  //进栈操作后不满足出栈条件,直接失败处理;
			Flag=false;
			return;
		}
		else{  //满足出栈条件,继续下一步测试;
			S.pop();
			i++;
		}
	}
	Flag=true;
}

void Process(){
	int i;
	while(K-->0){
		for(i=0;i<N;i++)
			scanf("%d",&A[i]);
		Judge();
		if(Flag)
			printf("YES\n");
		else
			printf("NO\n");
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
