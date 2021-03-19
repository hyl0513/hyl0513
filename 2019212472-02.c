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
linenode *ru(linenode *q){//������Ŷ� 
	node *p;
	p=(node*)malloc(sizeof(node));
	if(p==NULL){
		exit(0);
	}
	q->rear->next=p;
	q->rear=p;
	printf("����������");
	scanf("%s",p->x);
	printf("���뿨�ţ�");
	scanf("%d",&p->k);
	q->rear->next=NULL;
	return q;
}
linenode *chu(linenode *p){//�Ͳ� 
	if(p->front==p->rear){
		printf("�����Ŷ�");
		return p;
	}
	else{
		p->front=p->front->next;
		printf("�ͲͿ��ˣ�%s\t���ţ�%d\n",p->front->x,p->front->k);
	}
	return p;
}
void shanchu(linenode *p,int *w){//ɾ��ָ��λ�� 
	int n,i;
	node *q,*m;
	q=p->front;
	printf("ɾ��λ�ã�");
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
	printf("ɾ��ʧ��\n");
}
}
void charu(linenode *q,int *w){//����ָ��λ�� 
	int k,i;
	node *p,*s;
	p=q->front;
	printf("��������λ�ã�");
	scanf("%d",&k);
	if(k<=(*w)+1){
	for(i=1;i<k;i++){
		p=p->next;
	}
	if(p->next==NULL){
		s=(node*)malloc(sizeof(node));
		printf("����������");
		scanf("%s",s->x);
		printf("���뿨�ţ�");
		scanf("%d",&s->k);
		s->next=p->next;
		p->next=s;
		q->rear=s;
		(*w)++;
	}else{
	s=(node*)malloc(sizeof(node));
	printf("����������");
	scanf("%s",s->x);
	printf("���뿨�ţ�");
	scanf("%d",&s->k);
	s->next=p->next;
	p->next=s;
	(*w)++;
	}}
	else{
		printf("����ʧ��\n");
	}
}
int chazhao(linenode *t){
	char s[10];
	node *q;
	int i=1;
	printf("���ҵ�������");
	scanf("%s",s);
	q=t->front->next;
	while(q!=NULL){
		if(strcmp(s,q->x)==0){
			printf("���ҳɹ�\n");
			return i;
		}
		else{
			q=q->next;
			i++;
		}
	}
	if(q==NULL){
		printf("����ʧ��\n");
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
		printf("�������Ŷӡ�\n");
	}else{
	printf("����\t\t����\n");
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
	printf("�Ŷӵ�������%d\n������ǰ��������Ϣ����\n������󷽿�����Ϣ����\n",s);
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	int c;
	printf("���ֻ��˵���\n");
	printf("1.�����Ŷ�����\n2.���žͲ�\n3.���\n4.ɾ������\n5.���ҿ��ˣ���������\n6.���򣨰����ţ�\n7.������п�����Ϣ\n8.�˳�:ctrl+z\n");
	printf("\nѡ���ܣ�");
	while(scanf("%d",&c)!=EOF){
		switch(c){
			case 1:printf("�����Ŷ�������");
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
				printf("�����ڵ�%dλ\n",z);	
			};break;
			case 6:shu=paixu(shu,n);
			printf("����\t\t����\n");
			zhongxu(shu);break;
			case 7:print(n);break;
		}
			for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("�Ŷӵ�������%d\n������ǰ��������Ϣ��\n����\t\t����\n%s\t\t%d\n������󷽿�����Ϣ��\n����\t\t����\n%s\t\t%d\n",s,n->front->next->x,n->front->next->k,n->rear->x,n->rear->k);
	for(a=0;a<15;a++){
		printf("-");
	}
	printf("\n");
	printf("���ֻ��˵���\n");
	printf("1.�����Ŷ�����\n2.���žͲ�\n3.���\n4.ɾ������\n5.���ҿ��ˣ���������\n6.���򣨰����ţ�\n7.������п�����Ϣ\n8.�˳�:ctrl+z\n");
	printf("\nѡ���ܣ�");
	}
	return 0;
}

