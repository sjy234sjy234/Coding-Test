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

struct p_fact{  //结构体和STL容器的熟练灵活应用;
	long long data,num;
}Temp;

long long N,N0;
vector<p_fact> Ans;

void Input(){
	scanf("%lld",&N);
	N0=N;
	Ans.clear();
}

bool IsPrime(long long x){
	if(x<2)
		return false;
	int i;
	long long l=sqrt((double)x);
	for(i=2;i<=l;i++)
		if(x%i==0)
			return false;
	return true;
}

void Process(){
	int i,j,k,temp;
	long long l;
	while(N!=1){
		if(IsPrime(N)){
			Temp.data=N;
			Temp.num=1;
			N=1;
			Ans.push_back(Temp);
		}
		else{
			l=sqrt((double)N);
			for(i=2;i<=l;i++){
				if(N%i==0)
					break;
			}
			Temp.data=i;
			Temp.num=1;
			N/=i;
			while(N%i==0){
				Temp.num++;
				N/=i;
			}
			Ans.push_back(Temp);
		}
	}
}

void Show(int k){
	printf("%lld",Ans[k].data);
	if(Ans[k].num>1)
		printf("^%lld",Ans[k].num);
}

void Display(){
	if(N0==1)  //这里要注意的一个情况就是当N=1的时候直接输出1=1;
		printf("1=1\n");
	else{	
		int i;	
		printf("%lld=",N0);	
		Show(0);	
		for(i=1;i<Ans.size();i++){		
			printf("*");		
			Show(i);	
		}	
		printf("\n");
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
