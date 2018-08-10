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

const char Refer[55][4]={"\0",
	"S1","S2","S3","S4","S5","S6","S7","S8","S9","S10","S11","S12","S13",
	"H1","H2","H3","H4","H5","H6","H7","H8","H9","H10","H11","H12","H13",
	"C1","C2","C3","C4","C5","C6","C7","C8","C9","C10","C11","C12","C13",
	"D1","D2","D3","D4","D5","D6","D7","D8","D9","D10","D11","D12","D13",
    "J1","J2"};
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
	printf("%s",Refer[Card[1]]);
	for(int i=2;i<=54;i++)
		printf(" %s",Refer[Card[i]]);
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