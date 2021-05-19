#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 48
#define ElemType int
typedef struct
{
	int data[MAXSIZE];
	int front;
	int rear;
}SqQueue;

void InitQueue(SqQueue*&Q)//��ʼ������
{
	Q = (SqQueue*)malloc(sizeof(SqQueue));
	Q->front = Q->rear = 0;
}

void DestroyQueue(SqQueue*&Q)//���ٶ���
{
	free(Q);
}

bool QueueEmpty(SqQueue*Q)//�ж϶����Ƿ�Ϊ��
{
	if (Q->front == Q->rear)
		return true;
	else
		return false;
}

bool QueueFull(SqQueue*Q)//�ж϶����Ƿ���
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue*&Q, ElemType &e)//���
{
	if (Q->front == (Q->rear + 1) % MAXSIZE)
		return false;
	Q->data[Q->rear] = e;
		Q->rear = (Q->rear + 1) % MAXSIZE;
		return true;
}

	bool DeQueue(SqQueue*&Q,ElemType &e)//����
    {
		if (Q->front == Q->rear)
			return false;
		e = Q->data[Q->front];
		Q->front = (Q->front + 1) % MAXSIZE;
		return true;
	}

	bool GetHead(SqQueue*Q, ElemType&e)//ȡ����Ԫ��
	{
		if(Q->front == Q->rear)
			return false;
		e = Q->data[Q->front];
		return true;
	}

	int main()
	{
		SqQueue*Q;
		int arr[]={0,1,2,3,4};
		int e,a;  
		InitQueue(Q);
		if(QueueEmpty(Q))
		  printf("�ö�Ϊ��\n");
		  else
		  printf("�öӲ�Ϊ��\n");
		for(int j=0;j<5;j++){		
		    EnQueue(Q,arr[j]);
			printf("��ӵ�Ԫ��Ϊ%d\n",arr[j]); 
	       }
	    if(QueueFull(Q))		
	    	printf("�ö�����\n");		
			else 
			printf("�ö�δ��\n"); 
		DeQueue(Q,a);
		    printf("���ӵ�Ԫ��Ϊ%d\n",a) ; 
		if(GetHead(Q,e))
		{
			printf("����Ԫ��Ϊ%d",e);
		}
		DestroyQueue(Q); 
     }
