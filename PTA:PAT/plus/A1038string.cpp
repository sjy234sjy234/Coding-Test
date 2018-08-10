#include<iostream>  //使用string后加上不得不用cin和cout,时间上会慢很多;
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

string Fra[10000];
int N;

bool cmp(string a,string b){  //此处直接输出a+b<b+a,就不再借助中间变量了,效率才高;
	return a+b<b+a;
}

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		cin>>Fra[i];
	sort(Fra,Fra+N,cmp);
}

void Process(){

}

void Display(){
	int i,j,l;
	bool flag=true;
	for(i=0;i<N;i++){
		l=Fra[i].size();
		for(j=0;j<l&&Fra[i][j]=='0';j++);
		if(j<l){
			flag=false;
			for(;j<l;j++)
				printf("%c",Fra[i][j]);
			break;
		}
	}
	for(i++;i<N;i++)
		cout<<Fra[i];
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