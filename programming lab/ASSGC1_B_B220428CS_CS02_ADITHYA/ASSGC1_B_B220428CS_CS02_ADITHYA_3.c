#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* Create_Node(int val) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}

int isDigit(char d) {
	return (d >= '0' && d <= '9');
}
int find_index(char ch[], int start, int end) {
	if (start > end) {
		return -1;
	}
	char stack[100];
	int top = -1;
	for (int i = start; i <= end; i++) {
		if (ch[i] == '(') {
			stack[++top] = ch[i];
		}
		else if (ch[i] == ')') {
			if (stack[top] == '(') {
				top--;
				if (top == -1) {
					return i;
				}
			}
		}
	}
	return -1;
}
struct Node* Construct_Tree(char ch[], int start, int end) {
	if (start > end) {
		return NULL;
	}
	int num = 0;
	while (start <= end && ch[start] >= '0' && ch[start] <= '9') {
		num *= 10;
		num += (ch[start] - '0');
		start++;
	}
	struct Node* root = (struct Node*)malloc(sizeof(struct Node));
	root = Create_Node(num);
	int index = -1;
	if (start <= end && ch[start] == '(') {
		index = find_index(ch, start, end);
	}
	if (index != -1) {
		root->left = Construct_Tree(ch, start + 1, index - 1);
		root->right = Construct_Tree(ch, index + 2, end - 1);
	}
	return root;
}
void Find_Nodes(struct Node* root, int a, int b) {
	if (root == NULL) {
		return;
	}
	Find_Nodes(root->left, a, b);
	if (root->data >= a && root->data <= b) {
		printf("%d ", root->data);
	}
	Find_Nodes(root->right, a, b);
}

void Print_Actrs(struct Node* root, int k) {
	if (root == NULL) {
		return;
	}
	if (root->data < k) {
		Print_Actrs(root->right, k);
	}

	if (root->data > k) {
		Print_Actrs(root->left, k);
	}
	printf("%d ", root->data);
}
int main(int argc, char const* argv[]) {
	char ch[1000];
	scanf("%s", ch);

	struct Node* root = Construct_Tree(ch, 0, strlen(ch) - 1);
	//postTr(root);
	for (int i = 0; i < 2; i++) {
		char input;
		scanf(" %c", &input);
		if (input == 'a') {
			// all ancestors of k in bst
			int k;
			scanf(" %d", &k);
			Print_Actrs(root, k);
			printf("\n");
		} else if (input == 'p') {
			int a, b;
			scanf(" %d %d", &a, &b);
			Find_Nodes(root, a, b);
			printf("\n");
		}
	}
	return 0;
}
