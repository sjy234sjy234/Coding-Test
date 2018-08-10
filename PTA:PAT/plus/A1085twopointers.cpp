#include<iostream>  //此处用了Two Pointer思想,i,j都只可能往右走,直到j走到界,第一个j的定位借助了折半查找;
#include<algorithm>  //此方法略优于单纯的折半查找;
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

int HalfSearch(){  //利用折半查找定位j的初始值;
	int low=0,high=N-1,mid;  //要注意到折半查找时low和high是可能越界(-1和N位置)的;
	long long guard=P*A[0];
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
	long long guard;
	j=HalfSearch();
	Max=j+1;
	i=1;
	while(j<N-1){  //i,j一起往右走,直到j过界为止;
		guard=P*A[i];
		while(j<N-1&&A[j+1]<=guard)  //j往右走,直到满足条件或走到数组边界;
			j++;
		if(j-i+1>Max)
			Max=j-i+1;
		i++;
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