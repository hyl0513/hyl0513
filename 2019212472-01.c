#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct student{
	int xuehao;
	char xingming[10];
	char xingbie[4];
}student;
void luru(student s[],int *a){//功能1 
	int n,i;
	printf("录入学生人数：");
	scanf("%d",&n);
	while(n){
		(*a)++;
		printf("输入学号：");
		scanf("%d",&s[*a].xuehao);
		printf("输入姓名：");
		scanf("%s",s[*a].xingming);
		printf("输入性别：");
		scanf("%s",s[*a].xingbie);
		n--;
	} 
}
void shancu(student s[],int *a){//功能2 
	if((*a)==-1){
		printf("没有信息，删除失败\n");
	}else{
		(*a)--;
}
}
void charu(student s[],int *a){//功能3 
	int n;
	printf("插入信息位置：");
	scanf("%d",&n);
	if((*a)==9||n>((*a)+2)){
		printf("插入失败\n");
	}
	else{
	int b;
	b=(*a)+1;
	while(b>=n-1){
		s[b].xuehao=s[b-1].xuehao;
		strcpy(s[b].xingming,s[b-1].xingming);
		strcpy(s[b].xingbie,s[b-1].xingbie);
		b--;
	}
		printf("输入学号：");
		scanf("%d",&s[n-1].xuehao);
		printf("输入姓名：");
		scanf("%s",s[n-1].xingming);
		printf("输入性别：");
		scanf("%s",s[n-1].xingbie);
	(*a)++;
}
}
void shanchu4(student s[],int *a){//功能4 
	int n;
	printf("删除信息位置:");
	scanf("%d",&n); 
	if((*a)==-1||n>((*a)+1)){
		printf("删除失败\n");
	}
	else{
		int b=(*a);
		while(n<=b){
		s[n-1].xuehao=s[n].xuehao;
		strcpy(s[n-1].xingming,s[n].xingming);
		strcpy(s[n-1].xingbie,s[n].xingbie);
		n++;
		}
		(*a)--;
	}
}
void paixu(student s[],int n){//插入排序 
	int i,j;
	student x;
	for(i=1;i<n;i++){
		x.xuehao=s[i].xuehao;
		strcpy(x.xingming,s[i].xingming);
		strcpy(x.xingbie,s[i].xingbie);
		j=i;
		while(j>0&&x.xuehao<s[j-1].xuehao){
			s[j].xuehao=s[j-1].xuehao;
			strcpy(s[j].xingming,s[j-1].xingming);
			strcpy(s[j].xingbie,s[j-1].xingbie);
			j--;
		}
		s[j].xuehao=x.xuehao;
		strcpy(s[j].xingming,x.xingming);
		strcpy(s[j].xingbie,x.xingbie);
	}
}
void xingchazhao(student s[],int n){//姓名查找 
	int i;
	char x[10];
	printf("请输入要查找的姓名：");
	scanf("%s",x);
	for(i=0;i<=n;i++){
		if(strcmp(s[i].xingming,x)==0){
			break;
		}
	}
	if(i<=n){
		printf("学生信息在录入的信息中\n");		
	}
	else{
		printf("学生信息不在已录入的信息中\n");
	}
}
void xuehaochazhao(student s[],int st,int e){//学号查找 
	int k,n,i=0;
	printf("请输入要查找的学号：");
	scanf("%d",&n);
	while(st<=e){
		k=(st+e)/2;
		if(s[k-1].xuehao==n){
			i=1;
		}
		if(s[k-1].xuehao<n){
			st=k+1;
		}
		else{
			e=k-1;
		}
	}
	if(i==1){
		printf("学生信息在录入的信息中\n");		
	}
	else{
		printf("学生信息不在已录入的信息中\n");
	}
}
void print(student s[],int n){
	int i;
	printf("学号\t姓名\t性别\n");
	for(i=0;i<=n;i++){
		printf("%d\t%s\t%s\n",s[i].xuehao,s[i].xingming,s[i].xingbie);
	}
}
int main(){
	student s[10];
	student z;
	int i=-1,n,a;
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("存储空间状态：\n");
	printf("1.未录入数据\n");
	printf("2.最近一次录入的学生信息：无\n\n");
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("数字化菜单：\n");
	printf("1.录入新的学生信息\n2.删除当前学生信息\n3.在指定位置插入学生信息\n4.删除指定位置的学生信息\n5.按姓名进行查找\n6.按学号进行查找\n7.输出所有学生信息\n8.退出：ctrl+z\n");
	printf("选择功能：");
	while(scanf("%d",&n)!=EOF){
		switch(n){
			case 1:luru(s,&i);
			z.xuehao=s[i].xuehao;
			strcpy(z.xingming,s[i].xingming);
			strcpy(z.xingbie,s[i].xingbie);
			break;
			case 2:shancu(s,&i);break;
			case 3:charu(s,&i);
			z.xuehao=s[i].xuehao;
			strcpy(z.xingming,s[i].xingming);
			strcpy(z.xingbie,s[i].xingbie);
			break;
			case 4:shanchu4(s,&i);break;
			case 5:xingchazhao(s,i);break;
			case 6:paixu(s,i+1);
			xuehaochazhao(s,1,i+1);break;
			case 7:print(s,i);break;
		}
			for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
		printf("\n存储空间状态：\n");
		if(i==-1){
			printf("1.未录入数据\n");
			printf("2.最近一次录入的学生信息：无\n\n");
		}
		else{
			if(i>-1||i<9){
				printf("1.还能继续录入\n");
			}
			else{
				printf("1.已经存满数据\n");	
			}
			printf("2.最近一次录入的学生信息：\n");
			printf("学号\t姓名\t性别\n");
			printf("%d\t%s\t%s\n\n",z.xuehao,z.xingming,z.xingbie);
		}
			for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
		printf("数字化菜单：\n");
		printf("1.录入新的学生信息\n2.删除当前学生信息\n3.在指定位置插入学生信息\n4.删除指定位置的学生信息\n5.按姓名进行查找\n6.按学号进行查找\n7.输出所有学生信息\n8.退出：ctrl+z\n");
		printf("选择功能：");
	}
	return 0;
}
