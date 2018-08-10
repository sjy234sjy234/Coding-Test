#include<iostream>  //注意静态查找和动态查找的区别,主要掌握静态查找;
#include<algorithm>  //较难的是二分查找对于边界情况的处理;
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

struct node{
	int i,j;
}Tmp;

const long long INF=10000000000000LL;
int N;
long long M,Min_Sum,S[100001];
vector<node> Ans;

void Input(){
	int i;
	long long s=0,temp;
	scanf("%d%lld",&N,&M);
	S[0]=0;
	s=0;
	for(i=1;i<=N;i++){
		scanf("%lld",&temp);
		s+=temp;
		S[i]=s;
	}
}

int HalfSearch(int left){
	int low,high,mid;
	low=left+1;
	high=N;
	while(low<=high){
		mid=(low+high)/2;
		if(S[mid]-S[left]==M)
			return mid;
		else if(S[mid]-S[left]<M)
			low=mid+1;
		else
			high=mid-1;
	}
	if(S[high]-S[left]>M)
		return high;
	else if(low<=N&&S[low]-S[left]>M) 
		return low;
	else
		return -1;
}

void Process(){
	int i,j;
	Min_Sum=INF;
	for(i=0;i<N;i++){
		j=HalfSearch(i);
		if(j==-1)
			break;
		else{
			if(S[j]-S[i]<Min_Sum){
				while(!Ans.empty())
					Ans.pop_back();
				Tmp.i=i+1;
				Tmp.j=j;
				Ans.push_back(Tmp);
				Min_Sum=S[j]-S[i];
			}
			else if(S[j]-S[i]==Min_Sum){
				Tmp.i=i+1;
				Tmp.j=j;
				Ans.push_back(Tmp);
			}
		}
	}
}

void Display(){
	for(int i=0;i<Ans.size();i++)
		printf("%d-%d\n",Ans[i].i,Ans[i].j);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
