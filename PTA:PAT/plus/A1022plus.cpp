#include<iostream>  //map可以映射到其他容器,加上迭代器,灵活应用,功能非常强大,set.find(),map.find;
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

int N,M,Num;
char Temp[88];
map<string,set<int>> MP1,MP2,MP3,MP4,MP5;
map<string,set<int>>::iterator It;  //map和各种容器的配合;
set<int>::iterator It_s;

void Input(){
	scanf("%d",&N);
	getchar();
	while(N-->0){
		scanf("%d",&Num);
		getchar();

		gets(Temp);
		MP1[Temp].insert(Num);  //书名映射;
		gets(Temp);
		MP2[Temp].insert(Num);  //作者映射;
		while(true){
			scanf("%s",Temp);
			MP3[Temp].insert(Num);  //关键词映射;
			if(getchar()=='\n')
				break;
		}
		gets(Temp);
		MP4[Temp].insert(Num);  //出版社映射;
		gets(Temp);
		MP5[Temp].insert(Num);  //年份映射;
	}
}

void Process(){
	scanf("%d",&M);
	getchar();
	while(M-->0){
		gets(Temp);
		printf("%s\n",Temp);
		switch(Temp[0]){
		case '1':
			It=MP1.find(Temp+3);
			if(It==MP1.end())
				printf("Not Found\n");
			else{
				for(It_s=It->second.begin();It_s!=It->second.end();It_s++)
					printf("%07d\n",*It_s);
			}
			break;
		case '2':
			It=MP2.find(Temp+3);
			if(It==MP2.end())
				printf("Not Found\n");
			else{
				for(It_s=It->second.begin();It_s!=It->second.end();It_s++)
					printf("%07d\n",*It_s);
			}
			break;
		case '3':
			It=MP3.find(Temp+3);
			if(It==MP3.end())
				printf("Not Found\n");
			else{
				for(It_s=It->second.begin();It_s!=It->second.end();It_s++)
					printf("%07d\n",*It_s);
			}
			break;
		case '4':
			It=MP4.find(Temp+3);
			if(It==MP4.end())
				printf("Not Found\n");
			else{
				for(It_s=It->second.begin();It_s!=It->second.end();It_s++)
					printf("%07d\n",*It_s);
			}
			break;
		case '5':
			It=MP5.find(Temp+3);
			if(It==MP5.end())
				printf("Not Found\n");
			else{
				for(It_s=It->second.begin();It_s!=It->second.end();It_s++)
					printf("%07d\n",*It_s);
			}
		}
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
