#include<iostream>  //坑点1)N1的范围在long long内,N2范围可能超出long long;2)Radix2范围是2—2^31-1;3)low不能从2开始,要遍历Ns中的字符;
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

bool Flag;
int Tag,L1,L2;
long long N1,N2,Radix1,Radix2;
char Ns1[11],Ns2[11];
map<char,int> MP;

void InitMap(){
	char i;
	for(i='0';i<='9';i++)
		MP[i]=i-'0';
	for(i='a';i<='z';i++)
		MP[i]=i-'a'+10;
}

void Input(){
	int i;
	char temp[11];
	scanf("%s%s%d%lld",Ns1,Ns2,&Tag,&Radix1);
	if(Tag==2){  //统一N1已知,N2未知;
		strcpy(temp,Ns1);
		strcpy(Ns1,Ns2);
		strcpy(Ns2,temp);
	}
	for(i=0;Ns1[i]=='0';i++);
	strcpy(temp,Ns1+i);
	strcpy(Ns1,temp);
	for(i=0;Ns2[i]=='0';i++);
	strcpy(temp,Ns2+i);
	strcpy(Ns2,temp);
	L1=strlen(Ns1);
	L2=strlen(Ns2);
	N1=0;
	for(i=0;i<L1;i++)
		N1=N1*Radix1+MP[Ns1[i]];
}

void GetN2(){
	N2=0;
	for(int i=0;i<L2;i++){
		N2=N2*Radix2+MP[Ns2[i]];
		if(N2<=0)
			return;
	}
}

void Process(){
	Flag=false;
	if(L2==1){
		N2=MP[Ns2[0]];
		Radix2=N2+1;
		if(N2==N1)
			Flag=true;
	}
	else{
		long long low=2,high=3000000000LL;
		for(int i=0;Ns2[i]!='\0';i++)
			if(MP[Ns2[i]]+1>low)
				low=1+MP[Ns2[i]];
		while(low<=high){
			Radix2=(low+high)/2;
			GetN2();
			if(N2==N1){
				Flag=true;
				break;
			}
			else if(N2>0&&N2<N1)
				low=Radix2+1;
			else
				high=Radix2-1;
		}
	}
}

void Display(){
	if(Flag)
		printf("%lld\n",Radix2);
	else
		printf("Impossible\n");
}

int main(){
	InitMap();
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}