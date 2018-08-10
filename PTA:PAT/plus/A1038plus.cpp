#include<iostream>  //此题的贪心很难想到,此外还要注意一个特殊测试点结果为0;
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

struct frag{
	char num[9];
	int value;
	bool operator<(const frag &b)const{
		char x[17],y[17];
		strcpy(x,num);
		strcat(x,b.num);
		strcpy(y,b.num);
		strcat(y,num);
		return strcmp(x,y)<0;
	}
}Fra[10000];

int N;

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++){
		scanf("%s",Fra[i].num);
		sscanf(Fra[i].num,"%d",&Fra[i].value);
	}
	sort(Fra,Fra+N);
}

void Process(){
}

void Display(){
	int i,j;
	bool flag=true;
	for(i=0;i<N&&Fra[i].value==0;i++);
	if(i<N){
		printf("%d",Fra[i].value);
		flag=false;
	}
	for(i++;i<N;i++)
		printf("%s",Fra[i].num);
	if(flag)
		printf("0");
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