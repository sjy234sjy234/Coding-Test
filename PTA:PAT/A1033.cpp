#include<iostream>  //此题的关键是分析理清3种情况;
#include<algorithm>  //此外,还有就是当出发点没有加油站的时候,最远距离为0;
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

struct station{
	double price,dist;
	bool operator<(const station &b)const{
		return dist<b.dist;
	}
}P[502];

int N;
const double INF=1000000000;
double Cmax,Davg,Dmax,D,Tank,X,Cost;

void Input(){
	scanf("%lf%lf%lf%d",&Cmax,&D,&Davg,&N);
	Dmax=Davg*Cmax;
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&P[i].price,&P[i].dist);
	sort(P,P+N);
	P[N].dist=D;  //在终点位置设置哨兵;
	P[N].price=0;
}

void Process(){  //关键是三种情况理清楚思路就可以了;
	if(P[0].dist>0)  //出发站没有加油站,直接置0;
		X=0;
	else{  //出发站有加油站,开始模拟;	
		int i,j,min_j;	
		double m;
		bool flag;	
		Tank=0;  //初始油箱空;	
		X=0;  //初始位置0;	
		i=0;	
		Cost=0;	
		while(i<N){  //未到达终点站;	
			flag=true;	
			m=INF;
			for(j=i;j<N&&P[j+1].dist-X<=Dmax;j++){	
				if(P[j+1].price<m){  //记录范围内最便宜的加油站;
					m=P[j+1].price;
					min_j=j+1;
				}
				if(P[j+1].price<P[i].price){  //可到达的范围内有最近的更加便宜的加油站,油量加到刚刚好出发去;							
					Cost+=P[i].price*((P[j+1].dist-X)/Davg-Tank);				
					X=P[j+1].dist;				
					Tank=0; 				
					i=j+1;				
					flag=false;				
					break;			
				}		
			}		
			if(flag){  //范围内没有更加便宜的加油站;		
				if(i==j){  //不能到达更远了;			
					X+=Dmax;				
					Cost+=P[i].price*(Cmax-Tank);			
					Tank=0;				
					break;		
				}		
				else{  //能到达的站里面没有更便宜的站,加满油出发走到范围内最便宜的油站;			
					Cost+=P[i].price*(Cmax-Tank);			
					Tank=Cmax-(P[min_j].dist-X)/Davg;			
					X=P[min_j].dist;		
					i=min_j;		
				}		
			}
		}
	}
}

void Display(){
	if(X==D)
		printf("%.2f\n",Cost);
	else
		printf("The maximum travel distance = %.2f\n",X);
}

int main(){
//	while(true){
	Input();
	Process();	
	Display();
//	}
	return 0;
}