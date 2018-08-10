#include<iostream>  //此处的科学计数法,默认了第一位不是0;
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

int Ex;
char Sign;
char A[10000],Num[10000];

void Input(){
	int i,j;
	scanf("%s",A);
	Sign=A[0];
	for(i=1,j=0;A[i]!='E';i++)
		if(A[i]<='9'&&A[i]>='0')
			Num[j++]=A[i];
	Num[j]='\0';
	sscanf(A+i+1,"%d",&Ex);
	if(Sign=='-')
		printf("-");
}

void Process(){
	int i,l=strlen(Num)-1;
	if(Ex<0){
		printf("0.");
		Ex++;
		while(Ex<0){
			printf("0");
			Ex++;
		}
		printf("%s\n",Num);
	}
	else if(Ex<l){
		for(i=0;i<=Ex;i++)
			printf("%c",Num[i]);
		printf(".%s\n",Num+i);
	}
	else if(Ex==l)
		printf("%s\n",Num);
	else{
		printf("%s",Num);
		for(i=0;i<Ex-l;i++)
			printf("0");
		printf("\n");
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