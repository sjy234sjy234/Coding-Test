#include<iostream>
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

int N,M,A[100000];

void Input(){
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++)
		scanf("%d",&A[i]);
	sort(A,A+N);
}

int HalfSearch(int left){
	int key=M-A[left];
	int low=left+1,high=N-1,mid;
	while(low<=high){
		mid=(low+high)/2;
		if(A[mid]==key)
			return mid;
		else if(key<A[mid])
			high=mid-1;
		else
			low=mid+1;
	}
	return 0;
}

void Process(){
	int i,j;
	for(i=0;i<N-1;i++){
		j=HalfSearch(i);
		if(j){
			printf("%d %d\n",A[i],A[j]);
			return;
		}
	}
	printf("No Solution\n");
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