/******************
 *                *
 *  广度优先遍历  *
 *                *
 ******************/
#include <iostream>
using namespace std;

struct Branch
{
	int cIdx;
	Branch *next;
};

struct TNode
{
	int data;
	Branch *first;
};

struct BTNode
{
	int data;
	BTNode *lChild;
	BTNode *rChild;
};

void testBTree(BTNode *root);
void testTree(TNode t[]);
void visit(BTNode *p);//访问结点
void visit(TNode *p);//访问结点
void BTlevel(BTNode *bt);//二叉树广度优先遍历
void Tlevel(TNode *tn, TNode tree[]);//树广度优先遍历

const int maxSize = 1000;
int arr[maxSize];
int arri = 0;

int main()
{
	TNode tree[maxSize];
	testTree(tree);
	Tlevel(tree, tree);
	cout << endl;
	BTNode BTree ;
	testBTree(&BTree);
	BTlevel(&BTree);
	cout << endl;
	return 0;
}


void visit(BTNode *p)
{
	//可打印
	cout << p->data << " -> ";
	//可存入数组
	//arr[arri++] = p->data;
}
void visit(TNode *p)
{
	//可打印
	cout << p->data << " -> ";
	//可存入数组
	//arr[arri++] = p->data;
}

void testBTree(BTNode *root)
{
	root->data = 1;
	root->lChild = NULL;
	root->rChild = NULL;
	BTNode *newp1 = new BTNode();
	newp1->data = 2;
	newp1->lChild = NULL;
	newp1->rChild = NULL;
	root->lChild = newp1;
	BTNode *newp2 = new BTNode();
	newp2->data = 3;
	newp2->lChild = NULL;
	newp2->rChild = NULL;
	root->rChild = newp2;
	BTNode *newp3 = new BTNode();
	newp3->data = 4;
	newp3->lChild = NULL;
	newp3->rChild = NULL;
	newp1->lChild = newp3;
	BTNode *newp4 = new BTNode();
	newp4->data = 5;
	newp4->lChild = NULL;
	newp4->rChild = NULL;
	newp1->rChild = newp4;
	BTNode *newp5 = new BTNode();
	newp5->data = 6;
	newp5->lChild = NULL;
	newp5->rChild = NULL;
	newp2->lChild = newp5;
	BTNode *newp6 = new BTNode();
	newp6->data = 7;
	newp6->lChild = NULL;
	newp6->rChild = NULL;
	newp2->rChild = newp6;
	BTNode *newp7 = new BTNode();
	newp7->data = 8;
	newp7->lChild = NULL;
	newp7->rChild = NULL;
	newp3->lChild = newp7;
	BTNode *newp8 = new BTNode();
	newp8->data = 9;
	newp8->lChild = NULL;
	newp8->rChild = NULL;
	newp3->rChild = newp8;
	BTNode *newp9 = new BTNode();
	newp9->data = 10;
	newp9->lChild = NULL;
	newp9->rChild = NULL;
	newp4->lChild = newp9;
	BTNode *newp10 = new BTNode();
	newp10->data = 11;
	newp10->lChild = NULL;
	newp10->rChild = NULL;
	newp5->rChild = newp10;
	BTNode *newp11 = new BTNode();
	newp11->data = 12;
	newp11->lChild = NULL;
	newp11->rChild = NULL;
	newp6->lChild = newp11;
	BTNode *newp12 = new BTNode();
	newp12->data = 13;
	newp12->lChild = NULL;
	newp12->rChild = NULL;
	newp6->rChild = newp12;
}

void testTree(TNode t[])
{
	for (int i = 0;i < 10;i++)
	{
		t[i].data = i + 1;
		t[i].first = NULL;
	}
	Branch *newB2 = new Branch();
	newB2->cIdx = 1;
	newB2->next = NULL;
	t[0].first = newB2;
	Branch *newB3 = new Branch();
	newB3->cIdx = 2;
	newB3->next = NULL;
	newB2->next = newB3;
	Branch *newB4 = new Branch();
	newB4->cIdx = 3;
	newB4->next = NULL;
	newB3->next = newB4;
	Branch *newB5 = new Branch();
	newB5->cIdx = 4;
	newB5->next = NULL;
	t[1].first = newB5;
	Branch *newB6 = new Branch();
	newB6->cIdx = 5;
	newB6->next = NULL;
	t[2].first = newB6;
	Branch *newB7 = new Branch();
	newB7->cIdx = 6;
	newB7->next = NULL;
	newB6->next = newB7;
	Branch *newB8 = new Branch();
	newB8->cIdx = 7;
	newB8->next = NULL;
	newB7->next = newB8;
	Branch *newB9 = new Branch();
	newB9->cIdx = 8;
	newB9->next = NULL;
	t[3].first = newB9;
	Branch *newB10 = new Branch();
	newB10->cIdx = 9;
	newB10->next = NULL;
	newB9->next = newB10;
}

void BTlevel(BTNode *bt)
{
	if (bt != NULL)
	{
		int front, rear;
		BTNode *queue[maxSize];
		front = rear = 0;
		BTNode *p;
		rear = (rear + 1) % maxSize;
		queue[rear] = bt;
		while (front != rear)
		{
			front = (front + 1) % maxSize;
			p = queue[front];
			visit(p);
			if (p->lChild != NULL)
			{
				rear = (rear + 1) % maxSize;
				queue[rear] = p->lChild;
			}
			if (p->rChild != NULL)
			{
				rear = (rear + 1) % maxSize;
				queue[rear] = p->rChild;
			}
		}
	}
}

void Tlevel(TNode *tn, TNode tree[])
{
	int front, rear;
	TNode *queue[maxSize];
	front = rear = 0;
	TNode *p;
	if (tn != NULL)
	{
		rear = (rear + 1) % maxSize;
		queue[rear] = tn;
		while (front != rear)
		{
			front = (front + 1) % maxSize;
			p = queue[front];
			visit(p);
			Branch *q = p->first;
			while (q != NULL)
			{
				rear = (rear + 1) % maxSize;
				queue[rear] = &tree[q->cIdx];
				q = q->next;
			}
		}
	}
}