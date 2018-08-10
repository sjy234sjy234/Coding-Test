#include<iostream>  //此处有两个终点,一个是heapsort的核心adjust(),还一个是不需要向之前归并排序一样的去模拟一趟趟比较,可以利用堆排序的性质直接在Sorting[]中找到待操作的点的位置;
#include<algorithm>
#include<string.h>
#include<ctype.h>
#include<stdio.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<math.h>
#include<stdlib.h>
#include<time.h>
#include<map>
#include<set>
using namespace std;

int N;
int Origin[101],Sorting[101],Temp[101];

void Input(){
	int i;
	scanf("%d",&N);
	for(i=1;i<=N;i++)
		scanf("%d",&Origin[i]);
	for(i=1;i<=N;i++)
		scanf("%d",&Sorting[i]);
}

bool IsInsert(){
	int i,j,temp,in_pos;
	for(i=2;i<=N&&Sorting[i]>=Sorting[i-1];i++);
	in_pos=i;
	for(;i<=N;i++)
		if(Sorting[i]!=Origin[i])
			return false;
	temp=Sorting[in_pos];
	for(j=in_pos-1;j>0&&Sorting[j]>temp;j--)
		Sorting[j+1]=Sorting[j];
	Sorting[j+1]=temp;
	return true;
}

void Adjust(int i,int n){
	int left,right,temp;
	left=2*i;
	right=left+1;
	if(left>n)
		return;
	else if(right>n){
		if(Sorting[i]<Sorting[left]){
			temp=Sorting[i];
			Sorting[i]=Sorting[left];
			Sorting[left]=temp;
			Adjust(left,n);
		}
	}
	else{
		temp=max(Sorting[left],Sorting[right]);
		if(temp==Sorting[left]){
			if(Sorting[i]<temp){
				Sorting[left]=Sorting[i];
				Sorting[i]=temp;
				Adjust(left,n);
			}
		}
		else{
			if(Sorting[i]<temp){
				Sorting[right]=Sorting[i];
				Sorting[i]=temp;
				Adjust(right,n);
			}
		}
	}
}

void Process(){
	if(IsInsert())
		printf("Insertion Sort\n");
	else{
		int i,j,k,temp;
		printf("Heap Sort\n");
		for(i=N;Sorting[i]>Sorting[i/2];i--);
		temp=Sorting[i];
		Sorting[i]=Sorting[1];
		Sorting[1]=temp;
		Adjust(1,i-1);
	}
}

void Display(){
	for(int i=1;i<N;i++)
		printf("%d ",Sorting[i]);
	printf("%d\n",Sorting[N]);
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}
