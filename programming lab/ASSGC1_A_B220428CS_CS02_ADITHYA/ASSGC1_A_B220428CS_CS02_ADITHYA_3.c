#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Node {
	int data;
	char name[100];
	char time[100];
	struct Node* next;
};
struct Node* createNode(char nm[], int a, char tm[]) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = a;
	strcpy(newnode->name, nm);
	strcpy(newnode->time, tm);
	newnode->next = NULL;
	return newnode;
}
int comp(char a[], char b[]) {
	for (int i = 0; i < 5; i++) {
		if (a[i] < b[i]) {
			return 1;
		}
		else if (a[i] > b[i]) {
			return 2;
		}
		else {
			continue;
		}
	}
}
struct Node* insert(struct Node* head, char nm[], int a, char tm[]) {
	struct Node* temp = createNode(nm, a, tm);
	if (head == NULL) {
		return temp;
	}
	struct Node* ptr = head;
	if (ptr->data < a) {
		temp->next = head;
		head = temp;
		return head;
	}
	else if (ptr->data == a) {
		int c = comp(tm, ptr->time);
		if (c == 1) {
			temp->next = head;
			head = temp;
			return head;
		}
		else if (c == 2) {
			struct Node* sec = ptr->next;
			ptr->next = temp;
			temp->next = sec;
			return head;
		}
	}
	while (ptr->next != NULL && ptr->next->data > a) {
		ptr = ptr->next;
	}
	if (ptr->next == NULL) {
		ptr->next = temp;
		return head;
	}
	else if (ptr->next->data == a) {
		int c = comp(tm, ptr->next->time);
		if (c == 1) {
			struct Node* sec = ptr->next;
			ptr->next = temp;
			temp->next = sec;
			return head;
		}
		else if (c == 2) {
			ptr = ptr->next;
			struct Node* sec = ptr->next;
			ptr->next = temp;
			temp->next = sec;
			return head;
		}
	}

	struct Node* sec = ptr->next;
	ptr->next = temp;
	temp->next = sec;
	return head;
}
struct Node* search(struct Node* head, char nm[], char tm[]) {
	if (head == NULL) {
		return NULL;
	}
	struct Node* ptr = head;
	while (ptr != NULL) {
		if (strcmp(nm, ptr->name) == 0 && strcmp(tm, ptr->time) == 0) {
			return ptr;
		}
		ptr = ptr->next;
	}
	return NULL;
}
struct Node* Delete(struct Node* head, char nm[], char tm[]) {
	struct Node* ptr = head;

	if (strcmp(nm, ptr->name) == 0 && strcmp(tm, ptr->time) == 0) {
		return head->next;
	}
	while (ptr->next != NULL) {
		if (strcmp(nm, ptr->next->name) == 0 && strcmp(tm, ptr->next->time) == 0) {
			ptr->next = ptr->next->next;
			break;
		}
		ptr = ptr->next;
	}
	return head;
}
void print_list(struct Node* head) {
	if (head == NULL) {
		return ;
	}
	struct Node* ptr = head;
	while (ptr != NULL) {
		printf("%s %d %s\n", ptr->name, ptr->data, ptr->time);
		ptr = ptr->next;
	}

}
int main() {
	struct Node* head = NULL;
	while (1) {
		char ch;
		scanf("%c", &ch);
		if (ch == 'a') {
			int a;
			char nm[100];
			char tm[100];
			scanf(" %s %d %s", &nm, &a, &tm);
			head = insert(head, nm, a, tm);
		}
		else if (ch == 'd') {
			char nm[100];
			char tm[100];
			scanf(" %s %s", &nm, &tm);
			struct Node* s = search(head, nm, tm);
			if (s == NULL) {
				printf("-1\n");
			}
			else {
				head = Delete(head, nm, tm);
			}

		}
		else if (ch == 't') {
			printf("%s %d %s\n", head->name, head->data, head->time);
			head = head->next;
		}
		else if (ch == 'p') {
			print_list(head);
		}
		else if (ch == 'e') {
			break;
		}
		else if (ch == 'u') {
			int a;
			char nm[100];
			char tm[100];
			scanf(" %s %s %d", &nm, &tm, &a);
			head = Delete(head, nm, tm);
			head = insert(head, nm, a, tm);
		}
		else if (ch == 'c') {
			printf("%s %d %s\n", head->name, head->data, head->time);
		}
		else if (ch == ' ') {
			break;
		}
	}
}
