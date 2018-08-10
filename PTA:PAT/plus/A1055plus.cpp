#include<iostream>  //此题坑点在于要对数据预处理提取前100相同的钱数的人;
#include<algorithm> //此题要好好把握出题人思路;
#include<string.h>  //此题关键的思想是不管三七二十一先排号序,输出时添加判断条件M和Aim和Amax即可;
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
	char name[10];
	int age,money;
	bool operator<(const person &b)const{
		if(money!=b.money)
			return money>b.money;
		else if(age!=b.age)
			return age<b.age;
		else
			return strcmp(name,b.name)<0;
	}
}P[100000],S[100000];

int N,K,M,Amin,Amax;
int Count[201];

void Input(){
	int i,j;
	scanf("%d%d",&N,&K);
	for(i=0;i<N;i++)
		scanf("%s%d%d",P[i].name,&P[i].age,&P[i].money);
	sort(P,P+N);
	for(i=j=0;i<N;i++){
		if(Count[P[i].age]<100){  //此处利用哈希方法来限制各年龄数目,代码变得非常简洁;
			Count[P[i].age]++;  //哈希思想无处不在;
			S[j++]=P[i];
		}
	}
	N=j;
}

void Process(){
	int i,k;
	bool flag;
	for(k=1;k<=K;k++){
		scanf("%d%d%d",&M,&Amin,&Amax);
		printf("Case #%d:\n",k);
		flag=true;
		for(i=0;i<N&&M;i++)
			if(S[i].age>=Amin&&S[i].age<=Amax){
				printf("%s %d %d\n",S[i].name,S[i].age,S[i].money);
				flag=false;
				M--;
			}
		if(flag)
			printf("None\n");
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