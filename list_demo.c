/*================================================================
*   Copyright (C) 2018 Sangfor Ltd. All rights reserved.
*   
*   文件名称：list_demo.c
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月11日
*   描    述：c++list链表类的c语言函数实现
*
================================================================*/


#include<stdlib.h>
//声明printf函数防止stdlio中的remove函数声明与下面函数重复
int printf(const char* Format,...);


typedef int _T;
typedef struct _Node{
	_T data;
	struct _Node* next;

}Node;
//创建空链表
Node* create(){
	Node* node=(Node*)malloc(sizeof(Node));
	node->next=NULL;
	return node;
}
//删除链表
void destroy(Node* head){
	Node* temp=NULL;
	while(head!=NULL){
		temp=head->next;
		free(head);
		head=temp;	
	}

}
//清空链表（即保留头结点）
void clear(Node* head){	
	Node* temp=NULL;
	temp=head->next;
	head->next=NULL;
	head=temp;
	while(head!=NULL){
		head=head->next;
		free(temp);
		temp=head;
		
	}
}
//头插法
void push_front(Node* head,_T data){
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=head->next;
	head->next=node;
}
//尾插法
void push_back(Node* head,_T data){
	while(head->next!=NULL){
		head=head->next;
	}
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=NULL;
	
	head->next=node;
}
//向指定位置插入
void insert(Node* head,int pos,_T data){
	while(pos--){
		if(head->next==NULL) break;
		head=head->next;
	}
	Node* node=(Node*)malloc(sizeof(Node));
	node->data=data;
	node->next=head->next;

	head->next=node;
}
//根据数据删除某一节点，返回是否成功删除该节点
int remove(Node* head, _T data){
	while(head->next!=NULL && head->next->data!=data){
		head=head->next;
	}
	if(head->next==NULL) return 0;
	Node* temp=head->next;
	head->next=head->next->next;
	free(temp);
	return 1;
}
//根据数据更新某一节点，返回是否成功更新
int update(Node* head,const _T _old,const _T _new){
	head=head->next;
	while(head!=NULL && head->data!=_old){
		head=head->next;
	}
	if(head->next==NULL) return 0;
	head->data=_new;
	return 1;
}
//根据数据查找节点,并返回节点指针
Node* find(Node* head,const _T data){
	head=head->next;
	while(head!=NULL && head->data!=data){
		head=head->next;	
	}
	if(head==NULL) return NULL;
	return head;
}
//判断链表是否为空
int empty(Node* head){

	return !(head->next);
}
//获得链表节点数目
int size(Node* head){
	int cnt=0;
	while(head->next!=NULL){
		cnt++;
		head=head->next;
	}
	return cnt;
}


/* 
 * 函数名：traverse
 * 函数功能:遍历节点，并根据传入的函数指针，对该节点进行某种操作
 * 参数详情:
 * head:链表头结点指针
 * visit:函数指针，该函数内部实现对链表节点的操作，并可以通过返回值，来判断是否执行
 *返回值:无
 *
 */

void traverse(Node* head,int(*visit)(_T* data)){
	head=head->next;
	while(head!=NULL){
		if(!visit(&(head->data))) break;
		head=head->next;
	}
}
int compare(const void*,const void*);
/*
 * 函数名字：sort
 * 函数功能：对链表中数据根据传入的比较函数指针进行排序操作
 * 参数详情：
 * head:链表头结点指针
 * compare:函数指针，函数内部实现对链表数据的比较
 * 
 * 返回值:无
 *
 * 方法一：对链表中的数据进行排序，并改变其顺序（效率极低）
 * 方法二：直接对链表进行排序，更换节点位置（效率高）
 *
 */
void sort(Node* head,int(*compare)(const void*,const void*)){
	/*Node* max=head->next;
	int i=0,j=0;
	for(i=0;i<size(head);i++){
		Node* temp;
		temp=head->next;
		for(j=0;j<size(head)-i-1;j++){
			if(compare(temp->data,max->data)){
				max=temp->data;	
			}
			temp=temp->next;
		}
		if()
		Node* findNode=find(head,max);
		_T buf=temp->data;
		max=find(*head,i+1);
	}*/
	/*Node* temp=head->next;
	Node* temp2=temp->next;
	int i=0,j=0;
	while(1){
		j++;
		for(i=0;i<j;i++){
			if(compare(temp->data,temp2->data)){
				
			}
			temp=temp->next;
		}
	}*/
	Node* temp=head->next;
	Node* temp2=temp->next;
	for(;temp!=NULL;temp=temp->next){
		for(temp2=head->next;temp2->next!=NULL;temp2=temp2->next){
			if(compare(&temp2->data,&temp2->next->data)){
				
				printf("%d %d\n",temp2->data,temp2->next->data);
				_T buf;
				buf=temp2->data;
				temp2->data=temp2->next->data;
				temp2->next->data=buf;
			}
			
		}
	
	}
}
//逆序
void inverted(Node* head){
	//方法一：尾部插入实现逆序
	
	Node* temp=head->next;
	while(temp->next!=NULL) temp=temp->next;
	while(head->next!=temp){
		Node* buf=head->next;
		head->next=buf->next;
		buf->next=temp->next;
		temp->next=buf;
	}
	//方法二：头部插入实现逆序
	/*if(head->next==NULL) return;
	
	Node* p=head->next->next;
	Node* q=NULL;
	head->next->next=NULL;
	while(p!=NULL){
		q=p->next;
		p->next=head->next;
		head->next=p;
		p=q;
	}*/
	
}

int show(_T* data){
	printf("%d ",*data);
	return 1;
}

int main(){
    
	Node* list=NULL;
	list=create();
	printf("%d\n",size(list));
    push_back(list,200);
	push_back(list,20);
	push_front(list,3);
	push_front(list,46);
	traverse(list,show);
	printf("\n");
    inverted(list); 
	traverse(list,show);
	printf("\n");
	sort(list,compare);
	traverse(list,show);
	printf("\n");
    return 0;
}
int compare(const void* v1,const void* v2){
	int a=*((int*)v1);
	int b=*((int*)v2);
	return a>b;
}
