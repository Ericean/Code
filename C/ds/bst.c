#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 1000
struct node
{
	int key;
	int val;
	int rank;
	struct node *left, *right;
};
typedef struct node* NODE;
static inline int size(NODE x)
{
	if (x == NULL) return 0;
	else return size(x->left) + size(x->right) + 1;
}
static inline int min(NODE x)
{
	if(x->left==NULL) return x->key;
	else  return min(x->left);
}
static inline int max(NODE x)
{
	if(x->right==NULL) return x->key;
	else  return max(x->right);
}
static inline NODE put(NODE x, int key, int val)
{
	if (x == NULL)
	{
		NODE item = (NODE)malloc(sizeof(struct node));
		item->left = item->right = NULL;	
		item->key = key;
		item->val = val;
		item->rank = 1;
		return item;
	}
	if (key > x->key) x->right = put(x->right, key, val);
	else if (key < x->key) x->left = put(x->left, key, val);
	else x->val = val;
	x->rank = size(x);
	return x;
}
static inline void traversal(NODE x)
{
	int top = -1;
	NODE stack[MAX];
	do
	{
		while (x != NULL)
		{
			top++;
			stack[top] = x;
			x = x->left;
		}
		x = stack[top];
		top--;
		printf("%d %d %d\n", x->key, x->val, x->rank);
		x = x->right;
	} while (!(x == NULL && top == -1));
}
int main()
{
	NODE root = NULL;
	root = put(root, 7, 8);
	root = put(root, 767, 99);
	root = put(root, 6, 89);
	root = put(root, 43, 898);
	root = put(root, 2, 987);
	root = put(root, 98, 9);
	root = put(root, 8, 4);
	root = put(root, 8, 6);
	traversal(root);
	printf("min is: %d\n",min(root));
	printf("max is: %d\n",max(root));
	printf("root  : %d\n",root->key);
	printf("pre is: %d\n",max(root->left));
	printf("suc is: %d\n",min(root->right));
	return 0;
}