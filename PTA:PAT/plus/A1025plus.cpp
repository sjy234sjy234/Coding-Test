#include<iostream>  //分段排序及全局排序,并利用递推记录名次;
#include<algorithm>  //这里较好的思想是对全局不再设置rank域,因为直接递推即可,节省了空间;
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
	int score,loca_num,loca_rank;
	bool operator<(const student &b)const{
		if(score!=b.score)
			return score>b.score;
		else
			return num<b.num;
	}
}Stu[30000];

int N,Total;

void Input(){
	int i,j,k,sta,len,r;
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
}

void Process(){

}

void Display(){
	int i,r;
	printf("%d\n",Total);
	r=1;
	printf("%013lld %d %d %d\n",Stu[0].num,r,Stu[0].loca_num,Stu[0].loca_rank);
	for(i=1;i<Total;i++){
		if(Stu[i].score!=Stu[i-1].score)
			r=i+1;
		printf("%013lld %d %d %d\n",Stu[i].num,r,Stu[i].loca_num,Stu[i].loca_rank);
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