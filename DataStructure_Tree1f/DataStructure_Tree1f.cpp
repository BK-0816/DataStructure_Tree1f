#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;
//		  1
//	  2		  7
//  3   6   8    9
//4   5        10 11 

TreeNode n1 = { 4, NULL, NULL };
TreeNode n2 = { 5, NULL, NULL };
TreeNode n3 = { 3, &n1, &n2 };
TreeNode n4 = { 6, NULL, NULL };
TreeNode n5 = { 2, &n3, &n4 };
TreeNode n6 = { 8, NULL, NULL };
TreeNode n7 = { 10, NULL, NULL };
TreeNode n8 = { 11, NULL, NULL };
TreeNode n9 = { 9, &n7, &n8 };
TreeNode n10 = { 7, &n6, &n9 };
TreeNode n11 = { 1, &n5, &n10 };
TreeNode* root = &n11;


int treeArray[] = { 0, 1, 2, 7, 3, 6, 8, 9, 4, 5, 0, 0, 0, 0, 10, 11 };
// �迭 ǥ�������� Ʈ���� ���� ��ȸ�ϴ� �Լ�
void ArrayPreorder(int index, int size) {
	if (index < size && treeArray[index] != 0) {
		printf(" %d", treeArray[index]);  // ���� ��� ���
		ArrayPreorder(2 * index, size);  // ���� �ڽ� ���� �̵�
		ArrayPreorder(2 * index + 1, size);  // ������ �ڽ� ���� �̵�
	}
}

// �迭 ǥ�������� Ʈ���� ���� ��ȸ�ϴ� �Լ�
void ArrayInorder(int index, int size) {
	if (index < size && treeArray[index] != 0) {
		ArrayInorder(2 * index, size);  // ���� �ڽ� ���� �̵�
		printf(" %d", treeArray[index]);  // ���� ��� ���
		ArrayInorder(2 * index + 1, size);  // ������ �ڽ� ���� �̵�
	}
}

// �迭 ǥ�������� Ʈ���� ���� ��ȸ�ϴ� �Լ�
void ArrayPostorder(int index, int size) {
	if (index < size && treeArray[index] != 0) {
		ArrayPostorder(2 * index, size);  // ���� �ڽ� ���� �̵�
		ArrayPostorder(2 * index + 1, size); // ������ �ڽ� ���� �̵�
		printf(" %d", treeArray[index]);  // ���� ��� ���
	}
}



// ���� ��ȸ
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		printf(" %d", root->data); 	// ��� �湮
		inorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void preorder(TreeNode* root) {
	if (root) {
		printf(" %d", root->data); 	// ��� �湮
		preorder(root->left);	// ���ʼ���Ʈ�� ��ȸ
		preorder(root->right);	// �����ʼ���Ʈ�� ��ȸ
	}
}
// ���� ��ȸ
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);	// ���� ���� Ʈ�� ��ȸ
		postorder(root->right);	// ������ ���� Ʈ�� ��ȸ
		printf(" %d", root->data); 	// ��� �湮
	}
}
int main(void)
{
	printf("<Linked Tree>");
	printf("\n");
	printf("1.���� ��ȸ=");
	preorder(root);
	printf("\n");
	printf("\n");

	printf("2.���� ��ȸ=");
	inorder(root);
	printf("\n");
	printf("\n");

	printf("3.���� ��ȸ=");
	postorder(root);
	printf("\n");
	printf("\n");

	int size = sizeof(treeArray) / sizeof(treeArray[0]);
	printf("<Array Tree>");
	printf("\n");

	printf("1.���� ��ȸ=");
	ArrayPreorder(1, size);
	printf("\n");
	printf("\n");

	printf("2.���� ��ȸ=");
	ArrayInorder(1, size);
	printf("\n");
	printf("\n");

	printf("3.���� ��ȸ=");
	ArrayPostorder(1, size);
	printf("\n");
	printf("\n");


	return 0;
}