#include<iostream>  //哈希表的灵活应用,贪心算法的灵活应用;
#include<algorithm>  //通常贪心算法是最难以想到的方法;
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

int N,Count,Step,Hash[100000];

void Input(){
	int temp,i;
	scanf("%d",&N);
	for(Count=i=0;i<N;i++){
		scanf("%d",&temp);
		Hash[temp]=i;
		if(temp==i)
			Count++;
	}
}

void Process(){
	int s_pos,p0,px;
	for(Step=0,s_pos=1;Hash[s_pos]==0||Hash[s_pos]==s_pos;s_pos++);  //始终保持s_pos指针指向用于处理特殊交换的最左位置;
	while(Count<N){
		if(Hash[0]!=0){  //若0位不为0,则置换0位里的数字到正确位置;
			Step++;  //Step累加;
			p0=Hash[0];  //取0位存放数字p0;
			px=Hash[p0];  //取p0位存放数字px;
			Hash[p0]=p0;  //将p0放到p0;
			Hash[0]=px;  //将0放到px;
			Count++;  //正确数字个数+1;
			if(Hash[0]==0)  //若此次0也被置换到0位上,正确数字个数再+1;
				Count++;
			for(;Hash[s_pos]==0||Hash[s_pos]==s_pos;s_pos++);  //始终保持s_pos指针指向用于处理特殊交换的最左位置;
		}
		else{  //若0位为0,则需要进行一次额外的特殊置换,将0交换到s_pos位置处,且Count数-1(少一个归位数);
			Step++;  //Step累加;
			px=Hash[s_pos];  //取s_pos位存放数字px;
			Hash[0]=px;  //将px放到0位;
			Hash[s_pos]=0;  //将0放到s_pos位;
			Count--;  //正确数字个数-1;
			for(;Hash[s_pos]==0||Hash[s_pos]==s_pos;s_pos++);  //始终保持s_pos指针指向用于处理特殊交换的最左位置;
		}
	}
}

void Display(){
	printf("%d\n",Step);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}