// 从右边看一颗二叉树的递归解法,不过还是层序遍历可以更好理解，只要保持遍历的顺序从上到下，从左到右即可
#include<stdio.h>
#include<stdlib.h>
#define SIZE 32
typedef struct _node{
	int val;
	struct _node* left;
	struct _node* right;
	int level;
} Node;

typedef struct _vector{
 	int array[SIZE];
	int size;
} Vector;

static Vector vector;

void rightSee(Node* root);

void recursive(Node* node);

int main(int argc,char* argv[]){
	Node* node1 = (Node*)malloc(sizeof(Node));
	node1->val = 1;
	node1->level = 0;

	Node* node2 = (Node*)malloc(sizeof(Node));
	node2->val = 2;
	node2->level = 1;

	Node* node3 = (Node*)malloc(sizeof(Node));
	node3->val = 3;
	node3->level = 1;

	Node* node4 = (Node*)malloc(sizeof(Node));
	node4->val = 4;
	node4->level = 2;

	Node* node5 = (Node*)malloc(sizeof(Node));
	node5->val = 5;
	node5->level = 2;

	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->left = NULL;
	node3->right = NULL;
	
	node4->left = NULL;
	node4->right = NULL;
	
	
	node5->left = NULL;
	node5->right = NULL;

	rightSee(node1);

	return 0;
}

void rightSee(Node* root){
	if(root == NULL)
		return;
	recursive(root);
	for(int i = 0; i< vector.size;i++){
		printf("%d\t",vector.array[i]);
	}
	putchar('\n');
}

// 该函数返回该节点的右边遍历的值
void recursive(Node* node){
	if(node == NULL)
		return;
	if(vector.array[node->level] == 0){
		vector.array[node->level] = node->val;
		vector.size ++;
	}else{
		vector.array[node->level] = node->val;
	}
	recursive(node->left);
	recursive(node->right);
}

