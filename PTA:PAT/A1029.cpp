#include<iostream>  //因为此处两个序列的长度是不相同的,因此不能使用折半查找;
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

int N1,N2,Half;
long long Ans,S1[1000000],S2[1000000];

void Input(){
	int i;
	scanf("%d",&N1);
	for(i=0;i<N1;i++)
		scanf("%lld",&S1[i]);
	scanf("%d",&N2);
	for(i=0;i<N2;i++)
		scanf("%lld",&S2[i]);
	Half=(N1+N2+1)/2;
}

void Process(){
	int i,j,k;
	i=j=k=0;
	while(i<N1&&j<N2){
		if(S1[i]<S2[j]){
			i++;
			k++;
			if(k==Half){
				Ans=S1[i-1];
				return;
			}
		}
		else{
			j++;
			k++;
			if(k==Half){
				Ans=S2[j-1];
				return;
			}
		}
	}
	while(i<N1){
		i++;
		k++;
		if(k==Half){
				Ans=S1[i-1];
				return;
			}
	}
	while(j<N2){
		j++;
		k++;
		if(k==Half){
				Ans=S2[j-1];
				return;
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
