#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	char x[10];
	int k;
	struct node *next;
}node;
typedef struct tree{
	char x[10];
	int k;
	struct tree *lnode;
	struct tree *rnode;
}tree;
typedef struct linenode{
	node *front;
	node *rear;
}linenode; 
linenode *create(linenode *p){
	p->front=p->rear;
	if(p->front==NULL&&p->rear==NULL){
		exit(0);
	}
	p->front->next=NULL;
	return p;
}
linenode *ru(linenode *q){//入队列排队 
	node *p;
	p=(node*)malloc(sizeof(node));
	if(p==NULL){
		exit(0);
	}
	q->rear->next=p;
	q->rear=p;
	printf("输入姓名：");
	scanf("%s",p->x);
	printf("输入卡号：");
	scanf("%d",&p->k);
	q->rear->next=NULL;
	return q;
}
linenode *chu(linenode *p){//就餐 
	if(p->front==p->rear){
		printf("无人排队");
		return p;
	}
	else{
		p->front=p->front->next;
		printf("就餐客人：%s\t卡号：%d\n",p->front->x,p->front->k);
	}
	return p;
}
void shanchu(linenode *p,int *w){//删除指定位置 
	int n,i;
	node *q,*m;
	q=p->front;
	printf("删除位置：");
	scanf("%d",&n);
	if(n<=(*w)){
	for(i=1;i<n;i++){
		q=q->next;
	}
	if(q->next->next==NULL){
		p->rear=q;
		q->next=NULL;
		(*w)--;
	} 
	else{
		m=q->next;
		q->next=m->next;
		free(m);
		(*w)--;
}
}
else{
	printf("删除失败\n");
}
}
void charu(linenode *q,int *w){//插入指定位置 
	int k,i;
	node *p,*s;
	p=q->front;
	printf("输入插入的位置：");
	scanf("%d",&k);
	if(k<=(*w)+1){
	for(i=1;i<k;i++){
		p=p->next;
	}
	if(p->next==NULL){
		s=(node*)malloc(sizeof(node));
		printf("输入姓名：");
		scanf("%s",s->x);
		printf("输入卡号：");
		scanf("%d",&s->k);
		s->next=p->next;
		p->next=s;
		q->rear=s;
		(*w)++;
	}else{
	s=(node*)malloc(sizeof(node));
	printf("输入姓名：");
	scanf("%s",s->x);
	printf("输入卡号：");
	scanf("%d",&s->k);
	s->next=p->next;
	p->next=s;
	(*w)++;
	}}
	else{
		printf("插入失败\n");
	}
}
int chazhao(linenode *t){
	char s[10];
	node *q;
	int i=1;
	printf("查找的姓名：");
	scanf("%s",s);
	q=t->front->next;
	while(q!=NULL){
		if(strcmp(s,q->x)==0){
			printf("查找成功\n");
			return i;
		}
		else{
			q=q->next;
			i++;
		}
	}
	if(q==NULL){
		printf("查找失败\n");
		return 0;
	}
}
void ctrebtree(tree **head,node *t){
	if((*head)!=NULL){
		if(t->k<(*head)->k){
			ctrebtree(&(*head)->lnode,t);
		}
		else{
			ctrebtree(&(*head)->rnode,t);
		}
	}
	
	else{
		*head=(tree*)malloc(sizeof(tree));
		(*head)->k=t->k;
		strcpy((*head)->x,t->x);
		(*head)->lnode=NULL;
		(*head)->rnode=NULL;
	}
}
tree *paixu(tree *h,linenode *q){
	node *p=NULL;
	p=q->front->next;
	while(p!=NULL){
		ctrebtree(&h,p);
		p=p->next;
	}
	return h;
} 
void zhongxu(tree *q){
	if(q!=NULL){
		zhongxu(q->lnode);
		printf("%s\t\t%d\n",q->x,q->k);
		zhongxu(q->rnode);
	}
}
void print(linenode *p){
	node *q;
	q=p->front->next;
	if(p->front==p->rear){
		printf("已无人排队。\n");
	}else{
	printf("姓名\t\t卡号\n");
	while(q!=NULL){
		printf("%s\t\t%d\n",q->x,q->k);
		q=q->next;
	}
}
}
int main(){
	linenode *n;
	n=(linenode*)malloc(sizeof(linenode));
	n->front=(node*)malloc(sizeof(node));
	n->rear=(node*)malloc(sizeof(node));
	n=create(n);
	tree *shu=NULL;
	int z,b,a,i,s=0;
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("排队的人数：%d\n队伍最前方客人信息：无\n队伍最后方客人信息：无\n",s);
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	int c;
	printf("数字化菜单：\n");
	printf("1.新增排队人数\n2.安排就餐\n3.插队\n4.删除客人\n5.查找客人（按姓名）\n6.排序（按卡号）\n7.输出所有客人信息\n8.退出:ctrl+z\n");
	printf("\n选择功能：");
	while(scanf("%d",&c)!=EOF){
		switch(c){
			case 1:printf("新增排队人数：");
			scanf("%d",&b); 
			for(i=0;i<b;i++){
			n=ru(n);
			s++;
			};
			break;
			case 2:chu(n);s--;break;
			case 3:charu(n,&s);break;
			case 4:shanchu(n,&s);break;
			case 5:
			z=chazhao(n);
			if(z>0){
				printf("客人在第%d位\n",z);	
			};break;
			case 6:shu=paixu(shu,n);
			printf("姓名\t\t卡号\n");
			zhongxu(shu);break;
			case 7:print(n);break;
		}
			for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("排队的人数：%d\n队伍最前方客人信息：\n姓名\t\t卡号\n%s\t\t%d\n队伍最后方客人信息：\n姓名\t\t卡号\n%s\t\t%d\n",s,n->front->next->x,n->front->next->k,n->rear->x,n->rear->k);
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("数字化菜单：\n");
	printf("1.新增排队人数\n2.安排就餐\n3.插队\n4.删除客人\n5.查找客人（按姓名）\n6.排序（按卡号）\n7.输出所有客人信息\n8.退出:ctrl+z\n");
	printf("\n选择功能：");
	}
	return 0;
}

