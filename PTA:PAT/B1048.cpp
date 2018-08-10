#include<iostream>  //模拟类问题难点在于细节的把握;
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

char A[101],B[101],C[101];

void Input(){
	scanf("%s%s",A,B);
}

void Process(){
	int i,j,k,temp;
	i=strlen(A)-1;
	j=strlen(B)-1;
	k=99;
	C[100]='\0';
	while(i>=0&&j>=0){
		if(k%2){
			temp=(A[i]-'0'+B[j]-'0')%13;
			switch(temp){
			case 12:C[k--]='K';break;
			case 11:C[k--]='Q';break;
			case 10:C[k--]='J';break;
			default:C[k--]=temp+'0';
			}
		}
		else{
			temp=((B[j]-A[i])+10)%10;
			C[k--]=temp+'0';
		}
		i--;
		j--;
	}
	while(i>=0){
		if(k%2)
			C[k--]=A[i--];
		else{  //此处A[i]可能为0,因此必须要对10取余;
			temp=(10-(A[i--]-'0'))%10;
			C[k--]=temp+'0';
		}
	}
	while(j>=0)			
		C[k--]=B[j--];	
	k++;
	printf("%s\n",C+k);
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