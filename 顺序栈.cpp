#include<malloc.h>
#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
#define ElemType int 
typedef struct Stack
{
	ElemType data[MaxSize];
	int top; 
}SqStack;


void InitStack(SqStack*&S){//��ʼ��ջ 
S = (SqStack*)malloc(sizeof(SqStack));
	S->top=0;         
}


bool StackEmpty(SqStack *S){//�ж�ջ�Ƿ�Ϊ�� 
	if(S->top==0)
	  return true; 
	else
	  return false; 
} 

bool StackFull(SqStack*S)//�ж�ջ�Ƿ�Ϊ�� 
{
	if(S->top==MaxSize)
	return true;
	else
	return false;
	}

bool Push(SqStack* &S,char x)//��ջ
{ 
	if(S->top==MaxSize)      
	return false;
	S->data[S->top]=x;
	S->top++;
	return true;
} 

bool Pop(SqStack* &S,int &e){//��ջ 
	if(S->top==0)
	 return false;
	 S->top--;
	 e=S->data[S->top];
	 return true;
} 

bool GetTop(SqStack* S,int &x){//��ȡջ��Ԫ�� 
	if(S->top==0)      
	return false;
	x=S->data[S->top];
	return true;
} 

void DestroyStack(SqStack *&S)//����ջ 
{
   free(S);	
}


int main()
{ 
	SqStack *S;
	int x,e;
	char arr[]={'H','e','l','l','o'};
	InitStack(S);
	StackEmpty(S);
	for(int i=0;i<5;i++)
	{
		Push(S,arr[i]);
		printf("��ջ�ɹ�����ջԪ��Ϊ%c\n",arr[i]);
	}
	GetTop(S,x);
	Pop(S,e);
	GetTop(S,x);
	StackFull(S); 
	 } 
