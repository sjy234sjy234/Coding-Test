#include<iostream>  //此题坑点,题目的输入不会超过long long的范围的;
#include<algorithm>  //对于任何判断比较,最好能先放到变量中,再进行比较;
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

int T;
long long A,B,C;

void Input(){
	scanf("%d",&T);
}

bool GetAns(){
	long long s=A+B;  //A+B必须存入一个long long型变量,而不能直接比较;
	if((A>=0&&B<=0)||(A<=0&&B>=0))
		return s>C;
	else if(A>0){
		if(s>0)
			return s>C;
		else
			return true;
	}
	else{
		if(s<0)
			return s>C;
		else
			return false;
	}
	
}

void Process(){
	int i;
	bool ans;
	for(i=1;i<=T;i++){
		scanf("%lld%lld%lld",&A,&B,&C);
		ans=GetAns();
		if(ans)
			printf("Case #%d: true\n",i);
		else
			printf("Case #%d: false\n",i);
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