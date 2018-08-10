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
#include<map>
using namespace std;

struct record{
	long long left_p,right_t;
	bool is_a;
}R[100050];

int LA;
const long long FULL=1000000007;
long long Ans;
char A[100050];

void Input(){
	scanf("%s",A);
	LA=strlen(A);
}

void Process(){
	int i;
	long long c;

	c=0;  //求left_p,记录is_a;
	R[0].is_a=(A[0]=='A');  
	R[0].left_p=0;
	if(A[0]=='P')
		c++;
	for(i=1;i<LA;i++){
		R[i].is_a=(A[i]=='A');
		R[i].left_p=c;
		if(A[i]=='P')
			c++;
	}

	c=0;  //求right_t;
	R[LA-1].is_a=(A[LA-1]=='A');
	R[LA-1].right_t=0;
	if(A[LA-1]=='T')
		c++;
	for(i=LA-2;i>=0;i--){
		R[i].right_t=c;
		if(A[i]=='T')
			c++;
	}
}

void Display(){
	int i;
	Ans=0;
	for(i=0;i<LA;i++){  //遍历求解Ans,超出取余;
		if(R[i].is_a)
			Ans=(Ans+R[i].left_p*R[i].right_t)%FULL;
	}
	printf("%lld\n",Ans);  //输出Ans;
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}