#include<iostream>  //map映射、sscanf()的灵活应用,;
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

int N;
char A[15];
char Low[13][5]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
char High[13][5]={"\0","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
map<string,int> MP;

void InitMap(){
	MP["tam"]=13;MP["hel"]=26;MP["maa"]=39;MP["huh"]=52;
	MP["tou"]=65;MP["kes"]=78;MP["hei"]=91;MP["elo"]=104;
	MP["syy"]=117;MP["lok"]=130;MP["mer"]=143;MP["jou"]=156;

	MP["jan"]=1;MP["feb"]=2;MP["mar"]=3;MP["apr"]=4;
	MP["may"]=5;MP["jun"]=6;MP["jly"]=7;MP["aug"]=8;
	MP["sep"]=9;MP["oct"]=10;MP["nov"]=11;MP["dec"]=12;
	MP["tret"]=0;
}

void Input(){
	scanf("%d",&N);
	getchar();
}

void Disp1(){  //数字到字母;
	int h,l,s;
	sscanf(A,"%d",&s);		
	l=s%13;			
	s/=13;		
	h=s;		
	if(h==0)			
		printf("%s\n",Low[l]);		
	else if(l==0)			
		printf("%s\n",High[h]);		
	else			
		printf("%s %s\n",High[h],Low[l]);
}

void Disp2(){  //字母到数字;
	if(A[3]==' '){
		char h[4],l[4];
		sscanf(A,"%s%s",h,l);
		int s=MP[h]+MP[l];
		printf("%d\n",s);
	}
	else{
		int s=MP[A];
		printf("%d\n",s);
	}
}

void Process(){
	while(N-->0){
		gets(A);
		if(A[0]<='9'&&A[0]>='0')
			Disp1();
		else
			Disp2();
	}
}

void Display(){

}

int main(){
//	while(true){
	InitMap();
	Input();
	Process();
	Display();
//	}
	return 0;
}