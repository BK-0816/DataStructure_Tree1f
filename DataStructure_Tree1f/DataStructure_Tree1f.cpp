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
// 배열 표현법으로 트리를 전위 순회하는 함수
void ArrayPreorder(int index, int size) {
	if (index < size && treeArray[index] != 0) {
		printf(" %d", treeArray[index]);  // 현재 노드 출력
		ArrayPreorder(2 * index, size);  // 왼쪽 자식 노드로 이동
		ArrayPreorder(2 * index + 1, size);  // 오른쪽 자식 노드로 이동
	}
}

// 배열 표현법으로 트리를 중위 순회하는 함수
void ArrayInorder(int index, int size) {
	if (index < size && treeArray[index] != 0) {
		ArrayInorder(2 * index, size);  // 왼쪽 자식 노드로 이동
		printf(" %d", treeArray[index]);  // 현재 노드 출력
		ArrayInorder(2 * index + 1, size);  // 오른쪽 자식 노드로 이동
	}
}

// 배열 표현법으로 트리를 후위 순회하는 함수
void ArrayPostorder(int index, int size) {
	if (index < size && treeArray[index] != 0) {
		ArrayPostorder(2 * index, size);  // 왼쪽 자식 노드로 이동
		ArrayPostorder(2 * index + 1, size); // 오른쪽 자식 노드로 이동
		printf(" %d", treeArray[index]);  // 현재 노드 출력
	}
}



// 중위 순회
void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);	// 왼쪽서브트리 순회
		printf(" %d", root->data); 	// 노드 방문
		inorder(root->right);	// 오른쪽서브트리 순회
	}
}
// 전위 순회
void preorder(TreeNode* root) {
	if (root) {
		printf(" %d", root->data); 	// 노드 방문
		preorder(root->left);	// 왼쪽서브트리 순회
		preorder(root->right);	// 오른쪽서브트리 순회
	}
}
// 후위 순회
void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);	// 왼쪽 서브 트리 순회
		postorder(root->right);	// 오른쪽 서브 트리 순회
		printf(" %d", root->data); 	// 노드 방문
	}
}
int main(void)
{
	printf("<Linked Tree>");
	printf("\n");
	printf("1.전위 순회=");
	preorder(root);
	printf("\n");
	printf("\n");

	printf("2.중위 순회=");
	inorder(root);
	printf("\n");
	printf("\n");

	printf("3.후위 순회=");
	postorder(root);
	printf("\n");
	printf("\n");

	int size = sizeof(treeArray) / sizeof(treeArray[0]);
	printf("<Array Tree>");
	printf("\n");

	printf("1.전위 순회=");
	ArrayPreorder(1, size);
	printf("\n");
	printf("\n");

	printf("2.중위 순회=");
	ArrayInorder(1, size);
	printf("\n");
	printf("\n");

	printf("3.후위 순회=");
	ArrayPostorder(1, size);
	printf("\n");
	printf("\n");


	return 0;
}