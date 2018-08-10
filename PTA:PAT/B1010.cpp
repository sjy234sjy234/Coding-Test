#include<iostream>  //此题对于输入输出的把握非常重要;
#include<algorithm>  //弄清输入输出规律则不需要借助辅助数组;
#include<string.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<map>
using namespace std;

int Ex,Co;

void Input(){
	bool flag=false;
	while(true){
		scanf("%d%d",&Co,&Ex);
		if(Ex){
		if(flag)
			printf(" ");
		printf("%d %d",Co*Ex,Ex-1);
		flag=true;
		}
		if(getchar()=='\n')
			break;
	}
	if(!flag)
		printf("0 0");
	printf("\n");
}

void Process(){

}

void Display(){

}

int main(){
//	while(true){
	Input();
//	Process();
//	Display();
//	}
	return 0;
}