#include<stdio.h>
#include<stdlib.h>
#define MaxSize 20
#define ElemType char 
typedef struct BTNode{
	ElemType data;
	struct BTNode*lchild;
	struct BTNode*rchild;
}BTNode;

void InitBiTree(BTNode *&T)//��ʼ�������� 
{
	T = NULL;
}

void CreateBiTree(BTNode *&T, char *str)//���������� 
{
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, tag, j = 0;
	char ch;
	T = NULL;
	ch = str[j];
	while (ch != '\0')
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; tag = 1; break;
		case ')':top--; break;
		case ',':tag = 2; break;
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch;
			p->lchild = p->rchild = NULL;
			if (T == NULL)
				T = p;
			else
			{
				switch (tag)
				{
				case 1:St[top]->lchild = p;
					break;
				case 2:St[top]->rchild = p;
					break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void visite(BTNode *T)//���ʶ����� 
{
	if (T == NULL)
		printf("The node does not exist");
	else
		printf("%c", T->data);
}


void PrintBiTree(BTNode *T, int level)//������������� 
{
	if (T != NULL)
	{
		PrintBiTree(T->rchild, level + 1);
		if (level != 0)
		{
			for (int i = 0; i<4 * (level - 1); i++)
			{
				printf("%s", " ");
			}
			printf("%s", "---");
		}
		visite(T);
		printf("\n");
		PrintBiTree(T->lchild, level + 1);
	}
}

int BiTreeDepth(BTNode *T)//����������߶� 
{
	int ldep = 0;
	int rdep = 0;
	if (T == NULL)
		return 0;
	else{
		ldep = BiTreeDepth(T->lchild);
		rdep = BiTreeDepth(T->rchild);
		return(ldep>rdep) ? (ldep + 1) : (rdep + 1);
	}
	
}

 BTNode*FindNode(BTNode*T, ElemType x)//���ҽ�� 
{
	BTNode*p;
	if (T == NULL)
		return NULL;
	else if (T->data == x)
		return T;
	else
	{
		p = FindNode(T->rchild, x);
		if (p != NULL)
			return p;
		else
			return FindNode(T->rchild, x);
	}
}

void InOrderTraverse(BTNode *T)//������� 
{
	if (T != NULL)
	{
		InOrderTraverse(T->lchild);
		visite(T);
		InOrderTraverse(T->rchild);
	}
}

void LevelTraverse(BTNode *T)//��α��� 
{
	BTNode *p;
	BTNode *qu[MaxSize];
	int front, rear;
	front = rear = -1;
	rear++;
	qu[rear] = T;
	while (front != rear)
	{
		front = (front + 1) % MaxSize;
		p = qu[front];
		visite(p);
		if (p->lchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->lchild;
		}
		if (p->rchild != NULL)
		{
			rear = (rear + 1) % MaxSize;
			qu[rear] = p->rchild;
		}
	}
}

int GetNodeNum(BTNode *T)//������
{
	if (T == NULL)
		return 0;
	int lNum = GetNodeNum(T->lchild);
	int rNum = GetNodeNum(T->rchild);
	//printf("%d %d\n",lNum,rNum);
	return lNum + rNum + 1;
}


int main()
{
	BTNode *T;
	ElemType x;
	BTNode *p;
	int level = 0;
	char str[] = "(1(2,3(4(6),5)))";
	InitBiTree(T);
	CreateBiTree(T, str);
	puts("�������������");
	//visite(T);
	PrintBiTree(T, level);
	puts("�������");
	InOrderTraverse(T);
	puts(" ");
	puts("��α���");
	LevelTraverse(T);
	puts(" ");
	p=FindNode(T, '3');	
	if (p!=NULL&&p->rchild!=NULL)
	printf("3�������Һ��ӷֱ�Ϊ��%c %c",p->lchild->data,p->rchild->data);
	puts(" ");
	puts("���ĸ߶�Ϊ");
	printf("%d", BiTreeDepth(T));
	puts(" ");
	printf("������������Ϊ��%d\n", GetNodeNum(T));
	return 0;
}
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
