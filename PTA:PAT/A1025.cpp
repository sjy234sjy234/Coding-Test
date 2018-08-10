#include<iostream>  //分段排序及全局排序,并利用递推记录名次;
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

struct student{
	long long num;
	int score,loca_num,loca_rank,final_rank;
	bool operator<(const student &b)const{
		if(score!=b.score)
			return score>b.score;
		else
			return num<b.num;
	}
}Stu[30000];

int N,Total;

void Input(){
	int i,j,k,sta,len;
	scanf("%d",&N);
	for(i=1,k=0;i<=N;i++){
		scanf("%d",&len);
		sta=k;
		for(j=0;j<len;j++){
			Stu[k].loca_num=i;
			scanf("%lld%d",&Stu[k].num,&Stu[k].score);
			k++;
		}
		sort(Stu+sta,Stu+sta+len);
		Stu[sta].loca_rank=1;
		for(j=1;j<len;j++){
			if(Stu[sta+j].score==Stu[sta+j-1].score)
				Stu[sta+j].loca_rank=Stu[sta+j-1].loca_rank;
			else
				Stu[sta+j].loca_rank=j+1;
		}
	}
	Total=k;
	sort(Stu,Stu+Total);
	Stu[0].final_rank=1;
	for(i=1;i<Total;i++){
		if(Stu[i].score==Stu[i-1].score)
			Stu[i].final_rank=Stu[i-1].final_rank;
		else
			Stu[i].final_rank=i+1;
	}
}

void Process(){

}

void Display(){
	printf("%d\n",Total);
	for(int i=0;i<Total;i++)
		printf("%013lld %d %d %d\n",Stu[i].num,Stu[i].final_rank,Stu[i].loca_num,Stu[i].loca_rank);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}