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

bool Flag_Merge;
int N,Init[100],Sorting[100],Temp[100];


void Input(){
	int i;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		scanf("%d",&Init[i]);
	for(i=0;i<N;i++)
		scanf("%d",&Sorting[i]);
}

bool MergeSort(int l){  //利用递归判断并完成Merge操作,不对Sorting[]操作,避免影响后续Insert()操作;
	if(l>=N)
		return false;
	int i,j,k,step,p;
	step=l<<1;
	for(p=k=0;k<N;k+=step){
		i=k;
		j=k+l;
		while(i<k+l&&i<N&&j<k+step&&j<N){
			if(Init[i]<Init[j])
				Temp[p++]=Init[i++];
			else
				Temp[p++]=Init[j++];
		}
		while(i<k+l&&i<N)
			Temp[p++]=Init[i++];
		while(j<k+step&&j<N)
			Temp[p++]=Init[j++];
	}
	for(p=0;p<N;p++)
		Init[p]=Temp[p];
	if(Flag_Merge)
		return true;
	for(p=0;p<N&&Init[p]==Sorting[p];p++);
	if(p==N)
		Flag_Merge=true;
	return MergeSort(l<<1);
}

void Insert(){  //一趟Insert()操作;
	int i,j,temp;
	for(i=1;i<N&&Sorting[i]>=Sorting[i-1];i++);  //此处坑点,元素值可能是相同的;
	temp=Sorting[i];
	for(j=i-1;j>=0&&Sorting[j]>temp;j--)
		Sorting[j+1]=Sorting[j];
	Sorting[j+1]=temp;
	for(i=0;i<N;i++)
		Init[i]=Sorting[i];
}

void Process(){
	Flag_Merge=false;
	if(MergeSort(1))
		printf("Merge Sort\n");
	else{
		printf("Insertion Sort\n");
		Insert();
	}
}

void Display(){
	int i;
	printf("%d",Init[0]);
	for(i=1;i<N;i++)
		printf(" %d",Init[i]);
	printf("\n");
}

int main(){
//	while(true){
	Input();
	Process();
	Display();
//	}
	return 0;
}