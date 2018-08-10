#include<iostream>  //此题的坑点:当一个人的账单是0时是不需要输出的;
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
	string name;
	int time;
	bool on_off;
	bool operator<(const record &b)const{  //排序用的函数;
		if(name!=b.name)
			return name<b.name;
		else
			return time<b.time;
	}
}Rec[1000];

struct bill{  //账单结构体,记录某人某月的账单;
	string name;
	vector<int> phone_rec;
}BI[1000];

int N,K,Month;  //月份只需要一个全局变量,因为月份全都相同;
int Toll[24];

void Input(){
	int i,mo,da,ho,mi;
	char Temp[15];
	for(i=0;i<24;i++)
		scanf("%d",&Toll[i]);
	scanf("%d",&N);
	for(i=0;i<N;i++){
		cin>>Rec[i].name;
		scanf("%d:%d:%d:%d%s",&mo,&da,&ho,&mi,Temp);
		if(Temp[1]=='n')
			Rec[i].on_off=true;
		Rec[i].time=da*24*60+ho*60+mi;  //时间统一转化为分,逻辑更加清晰了;
	}
	Month=mo;
	sort(Rec,Rec+N);  //需要对电话记录排序,优先序:1)人名;2)时间;
}

void Process(){  //将需要记录的信息都记录到bill变量BI[1-K]中,其中灵活的运用了string和vector;
	int i;
	BI[0].name="\0";
	for(i=0,K=0;i<N-1;i++){  //BI[1-K]记录了K个需要输出的用户账单信息;
		if(Rec[i].on_off&&!Rec[i+1].on_off&&Rec[i].name==Rec[i+1].name){				
			if(Rec[i].name==BI[K].name)					
				BI[K].phone_rec.push_back(i);				
			else{					
				K++;					
				BI[K].name=Rec[i].name;					
				BI[K].phone_rec.push_back(i);				
			}
		}
	}
}

int printitem(int in,int out){  //输出一次通话的记录,in、out分别是通话开始结束的时间;
	int i,temp,out_t=out,in_t=in;
	int s,s0,s1,s2,in_d,in_h,in_m,out_d,out_h,out_m;

	s0=s1=s2=0;  //初始化中间变量,s0,s1,s2;

	in_m=in_t%60;  //初试化in时间为时分秒;
	in_t/=60;
	in_h=in_t%24;
	in_t/=24;
	in_d=in_t;

	out_m=out_t%60;  //初始化out时间为时分秒;
	out_t/=60;
	out_h=out_t%24;
	out_t/=24;
	out_d=out_t;

	for(i=temp=0;i<24;i++)  //计算s0;
		temp+=60*Toll[i];
	for(i=in_d;i<out_d;i++)
		s0+=temp;

	for(i=0;i<in_h;i++)  //计算s1;
		s1+=60*Toll[i];
	s1+=in_m*Toll[i];

	for(i=0;i<out_h;i++)  //计算s2;
		s2+=60*Toll[i];
	s2+=out_m*Toll[i];

	s=s0+s2-s1;  //计算s=s0+s2-s1,这种思路在日期时间的减法中很重要;

	printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",in_d,in_h,in_m,out_d,out_h,out_m,out-in,(double)s/100);  //输出此次通话;

	return s;  //返回此次通话费用;
}

void printlist(int k){
	int i,total;
	total=0;
	for(i=0;i<BI[k].phone_rec.size();i++)  //输出所有通话单次记录,并累加total;
		total+=printitem(Rec[BI[k].phone_rec[i]].time,Rec[BI[k].phone_rec[i]+1].time);
	printf("Total amount: $%.2f\n",(double)total/100);  //输出total;
}

void Display(){
	int i;
	for(i=1;i<=K;i++){
		cout<<BI[i].name<<" ";  //输出名字和月份;
		printf("%02d\n",Month);
		printlist(i);
	}
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}