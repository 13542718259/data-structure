#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define ElemType int
typedef struct LinkNode
{
	ElemType data;
	struct LinkNode *next;
 } LinkStack;
 
 
 void InitStack(LinkStack *&S)//��ʼ��ջ 
 {
 	S=(LinkStack*)malloc(sizeof(LinkStack));
 	S->next=NULL;
 }
 
 bool StackEmpty(LinkStack*S)//�ж�ջ�Ƿ�Ϊ�� 
 {
 	if(S->next==NULL)
 	return true;
 	else
 	return false; 
  } 
  
  bool Push(LinkStack*&S,char e)//��ջ 
  {
  	LinkStack *p;
  	p=(LinkStack *)malloc(sizeof(LinkStack));
  	p->data=e;
  	p->next=S->next;
  	S->next=p;
  	return true;
   } 
   
   
   bool Pop(LinkStack *&S,ElemType &e)//��ջ 
   {
   	LinkStack *p;
   	if(S->next==NULL)
   	return false;
   	p=S->next;
   	S->next=p->next;
   	e=p->data;
   	free(p);
   	return true;
   }
   
   
   bool GetTop(LinkStack*&S,ElemType &e)//ȡջ��Ԫ�� 
   {
   	if(S->next==NULL)
   	return false;
   	e=S->next->data;
   	return false;
   }
   
   void DestroyStack(LinkStack*&S)//����ջ 
   {
   	LinkStack *q,*p=S;
   	while(p!=NULL)
   	{
   		q=p;
   		p=p->next;
   		free(q);
	   }
	} 
   
   int main()
  {
   	LinkStack *S,*q;
	   int e;
	   char arr[]={'H','e','l','l','o'};
	   InitStack(S);
	   StackEmpty(S);
	    for(int i=0;i<5;i++)
	    {
	    	Push(S,arr[i]);
	    	printf("��ջ�ɹ�����ջԪ��Ϊ%c\n",arr[i]) ;
		}	
		GetTop(S,e);
		Pop(S,e);
		GetTop(S,e);
  } 
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
   
