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

int N,Max_Num;
vector<int> Ans,Temp;

void Input(){
	scanf("%d",&N);
}

bool IsPrime(int x){
	if(x<2)
		return false;
	int i,l=sqrt((double)x);
	for(i=2;i<=l;i++)
		if(x%i==0)
			return false;
	return true;
}

void Process(){
	int i,j,l,temp,c;
	Max_Num=0;
	if(IsPrime(N)){  //有一个特殊情况就是N本身是素数的时候是需要单独判断的;
		Ans.push_back(N);
		Max_Num=1;
		return;
	}
	else{  //其余情况都只需要遍历到sqrt(N)即可;
		Temp.clear();
		l=sqrt((double)N);
		for(i=2;i<=l;i++){
			if(N%i==0){
				c=1;
				temp=N/i;
				Temp.push_back(i);
				for(j=i+1;temp%j==0;j++){
					c++;
					temp/=j;
					Temp.push_back(j);
				}
				if(c>Max_Num){
					Ans=Temp;
					Max_Num=c;
				}
				Temp.clear();
			}
		}
	}
}

void Display(){
	printf("%d\n",Ans.size());
	printf("%d",Ans[0]);
	for(int i=1;i<Ans.size();i++)
		printf("*%d",Ans[i]);
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
