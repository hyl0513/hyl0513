#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
typedef struct student{
	int xuehao;
	char xingming[10];
	char xingbie[4];
}student;
void luru(student s[],int *a){//����1 
	int n,i;
	printf("¼��ѧ��������");
	scanf("%d",&n);
	while(n){
		(*a)++;
		printf("����ѧ�ţ�");
		scanf("%d",&s[*a].xuehao);
		printf("����������");
		scanf("%s",s[*a].xingming);
		printf("�����Ա�");
		scanf("%s",s[*a].xingbie);
		n--;
	} 
}
void shancu(student s[],int *a){//����2 
	if((*a)==-1){
		printf("û����Ϣ��ɾ��ʧ��\n");
	}else{
		(*a)--;
}
}
void charu(student s[],int *a){//����3 
	int n;
	printf("������Ϣλ�ã�");
	scanf("%d",&n);
	if((*a)==9||n>((*a)+2)){
		printf("����ʧ��\n");
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
		printf("����ѧ�ţ�");
		scanf("%d",&s[n-1].xuehao);
		printf("����������");
		scanf("%s",s[n-1].xingming);
		printf("�����Ա�");
		scanf("%s",s[n-1].xingbie);
	(*a)++;
}
}
void shanchu4(student s[],int *a){//����4 
	int n;
	printf("ɾ����Ϣλ��:");
	scanf("%d",&n); 
	if((*a)==-1||n>((*a)+1)){
		printf("ɾ��ʧ��\n");
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
void paixu(student s[],int n){//�������� 
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
void xingchazhao(student s[],int n){//�������� 
	int i;
	char x[10];
	printf("������Ҫ���ҵ�������");
	scanf("%s",x);
	for(i=0;i<=n;i++){
		if(strcmp(s[i].xingming,x)==0){
			break;
		}
	}
	if(i<=n){
		printf("ѧ����Ϣ��¼�����Ϣ��\n");		
	}
	else{
		printf("ѧ����Ϣ������¼�����Ϣ��\n");
	}
}
void xuehaochazhao(student s[],int st,int e){//ѧ�Ų��� 
	int k,n,i=0;
	printf("������Ҫ���ҵ�ѧ�ţ�");
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
		printf("ѧ����Ϣ��¼�����Ϣ��\n");		
	}
	else{
		printf("ѧ����Ϣ������¼�����Ϣ��\n");
	}
}
void print(student s[],int n){
	int i;
	printf("ѧ��\t����\t�Ա�\n");
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
	printf("�洢�ռ�״̬��\n");
	printf("1.δ¼������\n");
	printf("2.���һ��¼���ѧ����Ϣ����\n\n");
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("���ֻ��˵���\n");
	printf("1.¼���µ�ѧ����Ϣ\n2.ɾ����ǰѧ����Ϣ\n3.��ָ��λ�ò���ѧ����Ϣ\n4.ɾ��ָ��λ�õ�ѧ����Ϣ\n5.���������в���\n6.��ѧ�Ž��в���\n7.�������ѧ����Ϣ\n8.�˳���ctrl+z\n");
	printf("ѡ���ܣ�");
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
		printf("\n�洢�ռ�״̬��\n");
		if(i==-1){
			printf("1.δ¼������\n");
			printf("2.���һ��¼���ѧ����Ϣ����\n\n");
		}
		else{
			if(i>-1||i<9){
				printf("1.���ܼ���¼��\n");
			}
			else{
				printf("1.�Ѿ���������\n");	
			}
			printf("2.���һ��¼���ѧ����Ϣ��\n");
			printf("ѧ��\t����\t�Ա�\n");
			printf("%d\t%s\t%s\n\n",z.xuehao,z.xingming,z.xingbie);
		}
			for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
		printf("���ֻ��˵���\n");
		printf("1.¼���µ�ѧ����Ϣ\n2.ɾ����ǰѧ����Ϣ\n3.��ָ��λ�ò���ѧ����Ϣ\n4.ɾ��ָ��λ�õ�ѧ����Ϣ\n5.���������в���\n6.��ѧ�Ž��в���\n7.�������ѧ����Ϣ\n8.�˳���ctrl+z\n");
		printf("ѡ���ܣ�");
	}
	return 0;
}
