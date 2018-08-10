#include<iostream>  //string要慎用,只能用cin和cout;
#include<algorithm>  //此题坑点,Count为0时不输出人;
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

struct person{
	string name,birth;
}P[100000],Dead,Unborn;

int N,Count,Old,Young;

void Input(){
	Dead.name="NON";
	Dead.birth="1814/09/05";
	Unborn.name="NON";
	Unborn.birth="2014/09/07";
	cin>>N;
	Old=Young=-1;
}

void Process(){
	int i;
	Count=0;
	for(i=0;i<N;i++){
			cin>>P[i].name>>P[i].birth;
		if(P[i].birth<Unborn.birth&&P[i].birth>Dead.birth){
			Count++;
			if(Old==-1)
				Old=i;
			else if(P[i].birth<P[Old].birth)
				Old=i;
			if(Young==-1)
				Young=i;
			else if(P[i].birth>P[Young].birth)
				Young=i;
		}
	}
}

void Display(){
	if(Count>0)
		cout<<Count<<" "<<P[Old].name<<" "<<P[Young].name<<"\n";
	else
		cout<<Count<<"\n";
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}