#include<iostream>  //此题有一个深坑,就是当输入是0的时候,必须输出0.0000...*10^0;
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

struct num{
	char data[101];
	int ex;
}A,B;

int N;
char As[150],Bs[150];

void GetNum(num &X,char Xs[]){
	int i,lx,f_i,p_i,c;
	lx=strlen(Xs);

	for(i=0;Xs[i]=='0'||Xs[i]=='.';i++);  //先处理ex域;
	f_i=i;
	for(i=0;Xs[i]!='.'&&Xs[i]!='\0';i++);
	p_i=i;
	if(p_i>f_i)
		X.ex=p_i-f_i;
	else
		X.ex=p_i-f_i+1;
	for(i=0;i<N;i++)  //再处理data域;
		X.data[i]='0';
	X.data[N]='\0';
	if(f_i==lx){
		X.ex=0;
		return;
	}
	for(i=f_i,c=0;i<lx&&c<N;i++)
		if(Xs[i]!='.')
			X.data[c++]=Xs[i];
}

void Input(){
	scanf("%d%s%s",&N,&As,&Bs);
	GetNum(A,As);
	GetNum(B,Bs);
}

void Process(){
	if(A.ex==B.ex&&strcmp(A.data,B.data)==0)
		printf("YES 0.%s*10^%d\n",A.data,A.ex);
	else
		printf("NO 0.%s*10^%d 0.%s*10^%d\n",A.data,A.ex,B.data,B.ex);
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
