#include<iostream>  //简单排序,简单折半查找应用;
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
	int temp,real;
	bool operator<(const student &b)const{
		return temp<b.temp;
	}
}Stu[1050];

int N,M;

void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%lld%d%d",&Stu[i].num,&Stu[i].temp,&Stu[i].real);
	sort(Stu,Stu+N);
}

int HalfSearch(int key){
	int low=0,high=N-1,mid;
	while(low<=high){
		mid=(low+high)>>1;
		if(key==Stu[mid].temp)
			return mid;
		else if(key<Stu[mid].temp)
			high=mid-1;
		else
			low=mid+1;
	}
}

void Process(){
	int temp,pos;
	scanf("%d",&M);
	while(M-->0){
		scanf("%d",&temp);
		pos=HalfSearch(temp);
		printf("%014lld %d\n",Stu[pos].num,Stu[pos].real);
	}
}

void Display(){

}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}