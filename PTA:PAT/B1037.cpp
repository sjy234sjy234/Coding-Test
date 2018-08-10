#include<iostream>  //对结构体和重载函数的练手;
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

struct money{
	int g,s,k;
	money operator-(const money &b)const{
		int t=k+s*29+g*17*29-b.k-b.s*29-b.g*17*29;
		money temp;
		temp.k=t%29;
		t/=29;
		temp.s=t%17;
		t/=17;
		temp.g=t;
		return temp;
	}
	bool operator<(const money &b)const{
		if(g!=b.g)
			return g<b.g;
		else if(s!=b.s)
			return s<b.s;
		else
			return k<b.k;
	}
}S1,S2,Ans;

void Input(){
	scanf("%d.%d.%d",&S1.g,&S1.s,&S1.k);
	scanf("%d.%d.%d",&S2.g,&S2.s,&S2.k);

}

void Process(){
	if(S2<S1){
		printf("-");
		Ans=S1-S2;
	}
	else
		Ans=S2-S1;

}

void Display(){
	printf("%d.%d.%d\n",Ans.g,Ans.s,Ans.k);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}