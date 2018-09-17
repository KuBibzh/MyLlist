/*================================================================
*   
*   文件名称：main.cpp
*   创 建 者：baozhenhua(鲍振华)
*   创建日期：2018年09月12日
*   描    述：Mylist模版类的测试
*
================================================================*/


#include<iostream>
#include"MyList.h"
bool compare(const int&,const int&);
int main(){
   MyList<int> list1;
   int a=1,b=2,c=3,d=5,p=100;
   //插入检测
   list1.push_front(a);
   list1.push_back(b);
   //list1.traverse();
   list1.push_back(c);
   list1.insert(3,p);
   list1.push_back(a);
   list1.push_front(d);
   list1.traverse();
   //逆序检测
   list1.reverse();
   list1.traverse();
   //长度检测
   std::cout<<list1.size()<<std::endl;
   //排序检测
   list1.sort(compare);
   list1.traverse();
   //删除测试
   list1.remove(a);
   list1.traverse();
   //查找测试
   std::cout<<list1.find(d)<<std::endl;
   //更新测试
   list1.updata(a,d);
   list1.traverse();
   //清空测试和是否为空测试
   list1.clear();
   std::cout<<list1.size()<<std::endl;
   if(list1.empty()){
   		std::cout<<"为空"<<std::endl;
   }

    
    
    
    
    return 0;
}
bool compare(const int& a,const int& b){
	return a>b;
}
