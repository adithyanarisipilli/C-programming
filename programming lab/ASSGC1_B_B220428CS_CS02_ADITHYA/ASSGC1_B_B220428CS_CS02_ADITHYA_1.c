#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int val) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = val;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
struct Node* construct(int in[], int instart, int inend, int pre[], int prestart, int preend, int map[]) {
	if (instart > inend || prestart > preend) {
		return NULL;
	}
	struct Node* root = createNode(pre[prestart]);
	int idx = map[root->data]; //index of root;
	int noofele = idx - instart; //no. of elements in inorder,preorder
	root->left = construct(in, instart, idx - 1, pre, prestart + 1, prestart + noofele, map);
	root->right = construct(in, idx + 1, inend, pre, prestart + noofele + 1, preend, map);
	return root;
}
int maximum(int a, int b) {
	return (a > b) ? a : b;
}
void postTr(struct Node* root) {
	if (root == NULL) {
		return ;
	}
	postTr(root->left);
	postTr(root->right);
	printf("%d ", root->data);
}
int find_dia(struct Node* root, int* dm) {
	if (root == NULL) {
		return 0;
	}
	int lh = find_dia(root->left, dm);
	int rh = find_dia(root->right, dm);
	*dm = maximum(*dm, lh + rh + 1);
	return 1 + maximum(lh, rh);
}
void print_zigzag(struct Node* root, int n) {
	//we have to create a queue
	int k = 0;
	int front = 0;
	struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
	queue[k] = root;
	int flag = 0;
	k++;//index of the queue
	while (1) {
		int size = k - front;
		if (size == 0) {
			break;
		}
		int* arr = (int*)malloc(size * sizeof(int));
		for (int i = 0; i < size; i++) {
			struct Node* temp = queue[front];
			arr[i] = temp->data;
			front++;
			if (temp->left != NULL) {
				queue[k++] = temp->left;
			}
			if (temp->right != NULL) {
				queue[k++] = temp->right;
			}
		}
		if (flag == 0) {
			for (int i = 0; i < size; i++) {
				printf("%d ", arr[i]);
			}
		}
		else {
			for (int i = size - 1; i >= 0; i--) {
				printf("%d ", arr[i]);
			}
		}
		flag = !flag;

	}
}
int find_lleaf_sum(struct Node* root, int le) {
	if (root->left == NULL && root->right == NULL) {
		if (le == 1)
			return root->data;
		else
			return 0;
	}
	int ls = 0, rs = 0;
	if (root->left != NULL)
		ls = find_lleaf_sum(root->left, 1);
	if (root->right != NULL)
		rs = find_lleaf_sum(root->right, 0);
	return ls + rs;
}
void find_level_max(struct Node* root, int n) {
	//we have to create a queue
	int k = 0;
	int front = 0;
	struct Node** queue = (struct Node**)malloc(1000 * sizeof(struct Node*));
	queue[k] = root;
	k++;//index of the queue
	while (1) {
		int size = k - front;
		if (size == 0) {
			break;
		}
		int* arr = (int*)malloc(size * sizeof(int));
		for (int i = 0; i < size; i++) {
			struct Node* temp = queue[front];
			arr[i] = temp->data;
			front++;
			if (temp->left != NULL) {
				queue[k++] = temp->left;
			}
			if (temp->right != NULL) {
				queue[k++] = temp->right;
			}
		}
		int lev_max = 0;
		for (int i = 0; i < size; i++) {
			if (arr[i] > lev_max) {
				lev_max = arr[i];
			}
		}
		printf("%d ", lev_max);

	}
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d", &n);
	int in[n], pre[n];
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &in[i]);
		if (in[i] > maxi) {
			maxi = in[i];
		}
	}
	int* map = (int*)malloc((maxi + 1) * sizeof(int));
	for (int i = 0; i < maxi; i++) {
		map[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		map[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &pre[i]);
	}
	//now construct bt from the inputs
	//now create a map for inorder
	int instart = 0;
	int inend = n - 1;
	int prestart = 0;
	int preend = n - 1;

	struct Node* root = construct(in, instart, inend, pre, prestart, preend, map);
	while (1) {
		char ch;
		scanf("%c", &ch);
		if (ch == 'p') {
			//postorderTraversal
			postTr(root);
			printf("\n");
		}
		if (ch == 'd') {
			int dm = 0;
			find_dia(root, &dm);
			printf("%d\n", dm);
		}
		if (ch == 's') {
			int left = 0;
			int ans = find_lleaf_sum(root, left);
			printf("%d\n", ans);
		}
		if (ch == 'z') {
			//zigzag Traversal
			print_zigzag(root, n);
			printf("\n");
		}
		if (ch == 'm') {
			find_level_max(root, n);
			printf("\n");
		}
		if (ch == 'e') {
			break;
		}
	}
	return 0;
}
