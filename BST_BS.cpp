#define  _CRT_SECURE_NO_WARNINGS //解决scanf危险
#include <stdio.h>
#include <stdlib.h>

typedef int KeyType;

typedef struct BSTNode {
	KeyType data;
	struct BSTNode* lchild, * rchild;
}BSTNode, * BiTree;

typedef struct {
	KeyType* elem;
	int Tablelen;
}STable;

BSTNode* BST_Search(BiTree T, KeyType i, BiTree& p);
void midOrder(BiTree p, KeyType str[], KeyType& pos);
int BST_Insert(BiTree& T, KeyType i);
void Creat_BST(BiTree& T, KeyType str[], int n);
int Binary_Search(STable ST, KeyType key);

int main()
{
	BiTree Tree;
	BiTree parent;
	BiTree search;
	KeyType str[10];
	STable ST;
	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &str[i]);
	}
	Creat_BST(Tree, str, 10); //87 7 60 80 59 34 86 99 21 3
	KeyType pos = 0;
	midOrder(Tree, str, pos);
	printf("\n");
	ST.elem = str;
	ST.Tablelen = 10;
	pos = Binary_Search(ST, 21);
	printf("%d\n", pos);
}

void midOrder(BiTree p, KeyType str[], KeyType& pos)
{
	if (p != NULL)
	{
		midOrder(p->lchild, str, pos);
		printf("%3d", p->data);
		str[pos++] = p->data;
		midOrder(p->rchild, str, pos);
	}
}

int BST_Insert(BiTree& T, KeyType i)
{
	if (NULL == T)
	{
		T = (BiTree)malloc(sizeof(BSTNode));
		T->data = i;
		T->lchild = T->rchild = NULL;
		return 1;
	}
	if (T->data == i)
	{
		return 0;
	}
	else if (T->data > i)
	{
		BST_Insert(T->lchild, i);
	}
	else
	{
		BST_Insert(T->rchild, i);
	}
}

void Creat_BST(BiTree& T, KeyType str[], int n)
{
	T = NULL;
	int i = 0;
	while (i < n)
	{
		BST_Insert(T, str[i]);
		i++;
	}
}

int Binary_Search(STable ST, KeyType key)
{
	int low, high, mid;
	low = 0;
	high = ST.Tablelen - 1;
	while (low <= high)
	{
		mid = (low + high) / 2;
		if (ST.elem[mid] == key)
		{
			return mid;
		}
		else if (ST.elem[mid] > key)
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return -1;
}

