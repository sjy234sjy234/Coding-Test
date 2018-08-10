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

int MSize,N;
int Hah[15000];

bool IsPrime(int x){
	if(x<2)
		return false;
	int i,l=sqrt((double)x);
	for(i=2;i<=l;i++)
		if(x%i==0)
			return false;
	return true;
}

void Input(){
	scanf("%d%d",&MSize,&N);
	while(!IsPrime(MSize))
		MSize++;
}

void Process(){
	bool flag;
	int temp,in_pos,d_pos,step;
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		in_pos=temp%MSize;
		if(!Hah[in_pos]){
			Hah[in_pos]=true;
			printf("%d",in_pos);
			if(i<N-1)
				printf(" ");
		}
		else{
			step=0;
			flag=true;
			while(step<MSize){
				step++;
				d_pos=(in_pos+step*step)%MSize;
				if(!Hah[d_pos]){
					Hah[d_pos]=true;
					printf("%d",d_pos);
					if(i<N-1)
						printf(" ");
					flag=false;
					break;
				}
			}
			if(flag){
				printf("-");
				if(i<N-1)						
					printf(" ");				
			}
		}
	}
}

void Display(){
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
