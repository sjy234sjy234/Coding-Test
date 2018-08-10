#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int D,H,M;
char Str1[61],Str2[61],Str3[61],Str4[61];
char Week[7][4]={"SUN","MON","TUE","WED","THU","FRI","SAT"};

void Input(){
	scanf("%s%s%s%s",Str1,Str2,Str3,Str4);
}

void Process(){
	int i;
	for(i=0;Str1[i]!='\0'&&Str2[i]!='\0';i++)
		if(Str1[i]==Str2[i]&&Str1[i]<='G'&&Str1[i]>='A'){
			D=Str1[i]-'A'+1;
			D%=7;
			i++;
			break;
		}
	for(;Str1[i]!='\0'&&Str2[i]!='\0';i++)
		if(Str1[i]==Str2[i]){
			if((Str1[i]<='9'&&Str1[i]>='0')){
				H=Str1[i]-'0';
				break;
			}
			if((Str1[i]<='N')&&(Str1[i]>='A')){
				H=Str1[i]-'A'+10;
				break;
			}
		}
	for(i=0;Str3[i]!='\0'&&Str4[i]!='\0';i++)
		if((Str3[i]==Str4[i])&&((Str3[i]>='A'&&Str3[i]<='Z')||(Str3[i]>='a'&&Str3[i]<='z'))){
			M=i;
			break;
		}
	

}

void Display(){
	printf("%s %02d:%02d\n",Week[D],H,M);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}