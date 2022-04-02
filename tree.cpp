#include <stdio.h>
#include <stdlib.h>

typedef char BiElemType;
typedef struct BiTNode {
	BiElemType data;
	struct BiTNode* lchild;
	struct BiTNode* rchild;
}BiTNode,*BiTree;//树结构体

typedef struct tag {
	BiTree p;//树的某一个节点的地址
	struct tag* pnext;
}tag_t,*ptag_t;//辅助队列结构

void preOrder(BiTree p);

void preOrder(BiTree p)
{
	if (p != NULL)
	{
		putchar(p->data);//等价于visit函数
		preOrder(p->lchild);
		preOrder(p->rchild);
	}
}

int main()
{
	BiTree pnew;
	char c;
	BiTree tree = NULL;//树根
	ptag_t phead = NULL, ptail = NULL, listpnew, pcur;
	//abcdefghij
	while (scanf("%c", &c) != EOF)
	{
		if (c == '\n')
		{
			break;
		}
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = c;
		listpnew = (ptag_t)calloc(1, sizeof(tag_t));
		listpnew->p = pnew;
		if (NULL == tree)
		{
			tree = pnew;
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->pnext = listpnew;
			ptail = listpnew;
		}
		if (NULL == pcur->p->lchild)
		{
			pcur->p->lchild = pnew;
		}
		else if (NULL == pcur->p->rchild)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->pnext;
		}
	}

	printf("----------前序遍历-----------\n");
	preOrder(tree);
}
