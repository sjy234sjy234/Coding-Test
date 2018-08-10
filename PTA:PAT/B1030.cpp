#include<iostream>  //此处利用折半查找,两个情况需要注意:1)返回low可能越界;2)数据必须采用long long;
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

int N,Max;
long long P,A[100000];

void Input(){
	scanf("%d%lld",&N,&P);
	for(int i=0;i<N;i++)
		scanf("%lld",&A[i]);
	sort(A,A+N);
}

int HalfSearch(int left){
	int low=left,high=N-1,mid;
	long long guard=P*A[left];
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid]<=guard)
			low=mid+1;
		else
			high=mid-1;
	}
	if(low<N&&A[low]<=guard)
		return low;
	else
		return high;
}

void Process(){
	int i,j;
	Max=0;
	for(i=0;i<N&&i<N-Max;i++){
		j=HalfSearch(i);
		if(j-i+1>Max)
			Max=j-i+1;
	}
}

void Display(){
	printf("%d\n",Max);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}