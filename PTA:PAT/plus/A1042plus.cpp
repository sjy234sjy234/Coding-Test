#include<iostream>  //建立1-54到字符的映射,洗牌过程只对数字操作,加快速度;
#include<algorithm>  //当然也可以利用对13取余的操作来确定需要输出的结果;
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

const char Refer[6]="SHCDJ";
int K,Card[55],Order[55],Temp[55];

void Input(){
	int i;
	scanf("%d",&K);
	for(i=1;i<=54;i++){
		scanf("%d",&Order[i]);
		Card[i]=i;
	}
}

void Shuffle(){
	int i;
	for(i=1;i<=54;i++)
		Temp[Order[i]]=Card[i];
	for(i=1;i<=54;i++)
		Card[i]=Temp[i];
}

void Process(){
	while(K-->0)
		Shuffle();
}

void Display(){
	printf("%c%d",Refer[(Card[1]-1)/13],(Card[1]-1)%13+1);
	for(int i=2;i<=54;i++)
		printf(" %c%d",Refer[(Card[i]-1)/13],(Card[i]-1)%13+1);
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