#include<iostream>  //最关键的是一个由高位向低位推进的顺序过程;
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

int N,L;
long long Ans,Cum[16],Digit[15];

void Input(){
	int i;
	Ans=0;
	scanf("%d",&N);
	Cum[0]=0;
	Cum[1]=1;
	for(i=2;i<16;i++)
		Cum[i]=Cum[i-1]*10+pow(10.0,i-1);
}

void Process(){
	int i,j,temp;
	i=0;
	while(N>0){
		Digit[i++]=N%10;
		N/=10;
	}
	L=i-1;
	for(i=L;i>=0;i--){
		Ans+=Digit[i]*Cum[i];  //记录下高位包含产生的整cum的值;
		if(Digit[i]>1)  //记录下高位的零头值;
			Ans+=pow(10.0,i);
		else if(Digit[i]==1){				
			temp=0;						
			for(j=i-1;j>=0;j--)									
				temp=temp*10+Digit[j];						
			Ans+=temp+1;	
		}		
	}
}

void Display(){
	printf("%lld\n",Ans);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
