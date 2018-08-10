#include<iostream>  //这是天勤书上的算法实现,可以借鉴的有1)利用数组和全局变量把4个cmp()函数并到一个中;2)利用哈希的方法完成了查询操作,时间换空间;
#include<algorithm>  //尤其是利用了第1步以后,大大降低了代码复杂度,此外对于学生学号位数不太多的情况,查询利用哈希方法也是非常非常好的选择;
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
	int num;
	int score[4];
}Stu[2000];

int N,M,I_cmp;
int Rank_List[1000000][4];
char Refer[5]="ACME";

bool cmp(const student &a,const student &b){
	return a.score[I_cmp]>b.score[I_cmp];
}

void Input(){
	int i,j;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++){
		scanf("%d",&Stu[i].num);
		for(j=1;j<4;j++){
			scanf("%d",&Stu[i].score[j]);
			Stu[i].score[0]+=Stu[i].score[j];
		}
	}
}

void Process(){
	int i;
	for(I_cmp=0;I_cmp<4;I_cmp++){
		sort(Stu,Stu+N,cmp);
		Rank_List[Stu[0].num][I_cmp]=1;
		for(i=1;i<N;i++){
			if(Stu[i].score[I_cmp]!=Stu[i-1].score[I_cmp])
				Rank_List[Stu[i].num][I_cmp]=i+1;
			else
				Rank_List[Stu[i].num][I_cmp]=Rank_List[Stu[i-1].num][I_cmp];
		}
	}
}

void Display(){
	int key,min_i,j;
	while(M-->0){
		scanf("%d",&key);
		if(Rank_List[key][0]==0)
			printf("N/A\n");
		else{
			min_i=0;
			for(j=1;j<4;j++)
				if(Rank_List[key][j]<Rank_List[key][min_i])
					min_i=j;
			printf("%d %c\n",Rank_List[key][min_i],Refer[min_i]);
		}
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