#include<iostream>  //此题用到的思想很巧妙;
#include<algorithm>  //心得,尽量不要自己去实现映射,尽量都用map,hash等方法直接处理;
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

struct record{  //记录结点,用来原始登记和原始排序;
	char plate[8];
	int time;
	bool in_out;  //true->in,false->out;
	bool operator<(const record &b)const{
		int tmp=strcmp(plate,b.plate);
		if(tmp)
			return tmp<0;
		else 
			return time<b.time;
	}
}Rec[10000];

struct validnode{  //有效结点,用来查询;
	int time;
	bool in_out;  //true->in,false->out;
	bool operator<(const validnode &b)const{
		return time<b.time;
	}
}Valid[10000];

int N,K,V,Max;
map<string,int> Total;
map<string,int>::iterator It;
queue<string> Q;

void Input(){
	char status[4];
	int i,h,m,s;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++){
		scanf("%s%d:%d:%d%s",Rec[i].plate,&h,&m,&s,status);
		Rec[i].time=h*3600+m*60+s;
		if(status[0]=='i')
			Rec[i].in_out=true;
		else
			Rec[i].in_out=false;
	}
}

void Process(){
	int i;
	sort(Rec,Rec+N);
	for(i=V=0;i<N-1;i++){
		if(Rec[i].in_out&&!Rec[i+1].in_out&&strcmp(Rec[i].plate,Rec[i+1].plate)==0){  //一进一出且车牌号相同,为有效记录,需要登记到valid中,并更新Total;
			Total[Rec[i].plate]+=Rec[i+1].time-Rec[i].time;  //更新Total;
			Valid[V].in_out=true;  //记录有效结点;
			Valid[V++].time=Rec[i].time;
			Valid[V].in_out=false;
			Valid[V++].time=Rec[i+1].time;			
			i++;  //有效记录一次要多加一个步长,避免重复比较;
		}
	}
	sort(Valid,Valid+V);
	Max=0;
	for(It=Total.begin();It!=Total.end();It++){
		if(It->second>Max){
			Max=It->second;
			while(!Q.empty())
				Q.pop();
			Q.push(It->first);
		}
		else if(It->second==Max)
			Q.push(It->first);
	}
}

void Display(){
	int h,m,s,time,now,ans;
	ans=0;
	now=-1;
	while(K-->0){
		scanf("%d:%d:%d",&h,&m,&s);
		time=h*3600+m*60+s;
		for(;now<V-1&&Valid[now+1].time<=time;now++)
			if(Valid[now+1].in_out)
				ans++;
			else
				ans--;
		printf("%d\n",ans);
	}
	while(!Q.empty()){
		cout<<Q.front()<<" ";
		Q.pop();
	}
	s=Max%60;
	Max/=60;
	m=Max%60;
	Max/=60;
	h=Max;
	printf("%02d:%02d:%02d\n",h,m,s);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}