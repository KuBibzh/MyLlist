/*================================================================
*   
*   文件名称：MyList.h
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月12日
*   描    述：C++中list链表的实现
*   注    意：模板类声明和实现一般只能放在类中实现
*
================================================================*/


#ifndef _MYLIST_H_
#define _MYLIST_H_

#include<iostream>

template <typename T>

class MyList{
	private:
		typedef struct _Node{
			T data;
			_Node* next;
		}Node;
	public:
		Node* head;
	
	public:
		//构造函数
		MyList(){
			head=new Node;
			head->next=NULL;
		}
		//拷贝构造函数
		MyList(MyList& list){
			head=list->head;
		}

		//析构函数
		~MyList(){
			while(head!=NULL){
				Node* temp=head->next;
				delete temp;
				head=temp;
			}		
		}

		//清空链表
		void clear(){
			Node* temp=head->next;
			while(temp!=NULL){
				Node* buf=temp->next;
				delete temp;
				temp=buf;				
			}
			head->next=NULL;
		}
		//链表头部加入节点
		void push_front(T& data_buf){
			Node* node_new=new Node;

			node_new->data=data_buf;
			node_new->next=head->next;

			head->next=node_new;
		
		}
		//链表尾部加入节点
		void push_back(T& data_buf){


			Node* temp=head;
			while(temp->next!=NULL) temp=temp->next;

			Node* node_new=new Node;
		    node_new->data=data_buf;
			node_new->next=temp->next;
			
			temp->next=node_new;	

		
		}
		//朝指定位置插入节点
		void insert(int pos,const T& data_buf){
			Node* temp=head;
			while(temp->next!=NULL&&--pos){
				temp=temp->next;
			}
			
			Node* node_new=new Node;
			node_new->data=data_buf;
			node_new->next=temp->next;

			temp->next=node_new;
		}
		//移除一个跟指定数据相同的节点
		bool remove(const T& data_buf){
			Node* temp=head;
			while(temp->next!=NULL && temp->next->data!=data_buf){
				temp=temp->next;
			}
			if(temp->next==NULL){
				return false;
			}
			Node* buf=temp->next;
			temp->next=temp->next->next;
			delete buf;
			return true;			

		}
		//移除一个指定位置的节点
		
		//更新某一个跟指定数据相同的节点数据
		bool updata(const T& _old,const T& _new){
			Node* temp=head->next;
			while(temp!=NULL && temp->data!=_old) temp=temp->next;
			if(temp==NULL) return false;
			
			temp->data=_new;
			return true;
		}
		//根据数据查找节点在链表中的位置
		int find(const T& data_buf) const{
			Node* temp=head;
			int cnt=0;
			while(temp!=NULL && temp->data!=data_buf) {
				temp=temp->next;
				++cnt;
			}
			
			if(temp==NULL) return 0;

			return cnt;
		}
		//判断链表是否为空
		bool empty() const{
			return !head->next;
		}
		//获得链表长度
		int size() const{
			int cnt=0;
			Node* temp=head->next;
			while(temp!=NULL){
				temp=temp->next;
				++cnt;
			}
			return cnt;
		}
		//排序
		void sort(bool(*compare)(const T&,const T&)){
			int cnt=size();
			Node* temp_back=NULL;
			Node* max=head->next;
			for(int i=0;i<cnt-1;i++){
				temp_back=head->next;
				for(int j=0;j<cnt-1-i;j++){
					if(compare(temp_back->data,max->data)){
						max=temp_back;
					}
					if(temp_back->next==NULL) break;
					temp_back=temp_back->next;
				}
				if(max!=temp_back){
					T data_buf=temp_back->data;
					temp_back->data=max->data;
					max->data=data_buf;
					
				}
				max=head->next;
			}
		}
		//逆序
		void reverse(){
			Node* temp=head;
			while(temp->next!=NULL) temp=temp->next;
			
			while(head->next!=temp){
				Node* buf=head->next;
				head->next=buf->next;
				buf->next=temp->next;
				temp->next=buf;
			}

		}
		//遍历链表,可以根据其他函数对链表数据进行各种操作
		void traverse(/*bool(*handle)(T& data)=show*/){
			Node* temp=head->next;
			while(temp!=NULL){
				if(!show(temp->data)){
					break;
				}
				temp=temp->next;
			}
			std::cout<<std::endl;
		}
		//显示
		bool show(T& data_buf) const{
			std::cout<<data_buf<<" ";
			return 1;
		}

		MyList& operator+(MyList& list);

		

		

};
    
    
    
    
    
#endif
