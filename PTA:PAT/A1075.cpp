#include<iostream>  //此题对于判分的逻辑过程要理解透彻,才可以清晰的解决问题;
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
	int num,perfect,score[6],total;
	bool compile;
	bool operator<(const student &b)const{  //排序规则,注意bool变量其实也可以比较大小;
		if(total!=b.total)
			return total>b.total;
		else if(perfect!=b.perfect)
			return perfect>b.perfect;
		else if(compile!=b.compile)
			return compile>b.compile;
		else
			return num<b.num;
	}
}Stu[10001];

int N,K,M;
int Full_Score[6];

void Input(){
	int i,j,user,pro,obt;
	scanf("%d%d%d",&N,&K,&M);
	for(i=1;i<=K;i++)
		scanf("%d",&Full_Score[i]);  //记录下各题号的满分;
	for(i=1;i<=N;i++){
		Stu[i].num=i;  //因后面排序会打乱次序,必须先登记下学号;
		for(j=1;j<=K;j++)
			Stu[i].score[j]=-1;  //用-1表示未提交的状态;
	}
	for(i=0;i<M;i++){
		scanf("%d%d%d",&user,&pro,&obt);
		if(Stu[user].score[pro]<0)  //之前未提交,则首先登记为0,说明提交过了;
			Stu[user].score[pro]=0;
		if(obt>=0){  //是否为有效提交;
			Stu[user].compile=true;  //更新编译状态;
			if(obt>Stu[user].score[pro]){  //成绩比之前提交的高,需更新成绩;
				Stu[user].score[pro]=obt;
				if(obt==Full_Score[pro])  //更新达到满分的次数;
					Stu[user].perfect++;
			}
		}
	}
	for(i=1;i<=N;i++)
		for(j=1;j<=K;j++)
			if(Stu[i].score[j]>0)
				Stu[i].total+=Stu[i].score[j];  //计算每位学生的总分,但是注意-1不要加进来;
	sort(Stu+1,Stu+N+1);  //按要求排序;
}

void Process(){

}

void Display(){
	int i,j,r;
	Stu[0].total=1000;  
	for(i=r=1;i<=N;i++){
		if(!Stu[i].compile)  //遍历到不输出的学生则退出;
			break;
		if(Stu[i].total!=Stu[i-1].total)  //若前后总分不同,更新名次,否则不更新,名次跟随即可;
			r=i;
		printf("%d %05d %d",r,Stu[i].num,Stu[i].total);  //输出名次,学号,总分;
		for(j=1;j<=K;j++){
			if(Stu[i].score[j]>=0)
				printf(" %d",Stu[i].score[j]);  //输出分数;
			else
				printf(" -");  //未提交输出'-';
		}
		printf("\n");
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