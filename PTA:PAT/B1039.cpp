#include<iostream>  //简单的哈希应用;
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

char Offer[1010],Need[1010];
int Count[128],L1,L2;
bool Flag;

void Input(){
	int i;
	Flag=true;
	scanf("%s%s",Offer,Need);
	L1=strlen(Offer);
	L2=strlen(Need);
	for(i=0;i<128;i++)
		Count[i]=0;
	for(i=0;i<L1;i++)
		Count[Offer[i]]++;
	for(i=0;i<L2;i++){
		if(--Count[Need[i]]<0)
			Flag=false;
	}
}

void Process(){
	if(Flag)
		printf("Yes %d\n",L1-L2);
	else{
		int s=0;
		for(int i=0;i<128;i++)
			if(Count[i]<0)
				s-=Count[i];
		printf("No %d\n",s);
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