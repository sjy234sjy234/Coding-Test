#include<iostream>  //对于应试,应该尽量多用递归,可以大大简化编程和思维;
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

struct node{
	int data,i,j;
	bool operator<(const node &b)const{
		return data>b.data;
	}
}A[10001];

int N,H,W;

void GetHW(){
	W=sqrt((double)N);
	while(N%W)
		W--;
	H=N/W;
}

void Input(){
	scanf("%d",&N);
	GetHW();
	for(int i=0;i<N;i++)
		scanf("%d",&A[i].data);
	sort(A,A+N);
}

void GetPos(int t,int sta_pos,int h,int w){  //利用递归进行坐标的转换,逻辑更清晰;
	int i,k;
	if(h==1){
		for(i=0;i<w;i++){
			k=sta_pos+i;
			A[k].i=t;
			A[k].j=t+i;
		}
	}
	else if(w==1){
		for(i=0;i<h;i++){
			k=sta_pos+i;
			A[k].i=t+i;
			A[k].j=t;
		}
	}
	else{	
		for(i=0;i<w-1;i++){		
			k=sta_pos+i;		
			A[k].i=t;		
			A[k].j=t+i;	
		}	
		for(;i<w+h-2;i++){		
			k=sta_pos+i;		
			A[k].i=t+i+1-w;		
			A[k].j=t+w-1;	
		}	
		for(;i<2*w+h-3;i++){		
			k=sta_pos+i;		
			A[k].i=t+h-1;		
			A[k].j=t+2*w+h-i-3;	
		}	
		for(;i<2*w+2*h-4;i++){		
			k=sta_pos+i;		
			A[k].i=t+2*w+2*h-i-4;		
			A[k].j=t;	
		}	
		if(h>2&&w>2)  //递归转化坐标;
			GetPos(t+1,sta_pos+2*w+2*h-4,h-2,w-2);	
	}
}

bool cmp(const node &a,const node &b){
	if(a.i!=b.i)
		return a.i<b.i;
	else
		return a.j<b.j;
}

void Process(){
	GetPos(0,0,H,W);
	sort(A,A+N,cmp);
}

void Display(){
	int i;
	for(i=0;i<N;i++){
		if((i+1)%W==0)
			printf("%d\n",A[i].data);
		else
			printf("%d ",A[i].data);
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