#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* createNode(int k) {
	struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
	newnode->data = k;
	newnode->next = NULL;
	return newnode;
}
struct Node* insertAtTail(struct Node* head, int a) {
	struct Node* temp = createNode(a);
	if (head == NULL) {
		return temp;
	}
	struct Node* ptr = head;
	while (ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = temp;
	return head;
}
struct Node* search(struct Node* head, int ind) {
	if (head == NULL) {
		return NULL;
	}
	struct Node* ptr = head;
	int count = 1;
	while (ptr != NULL) {
		if (count == ind) {
			return ptr;
		}
		ptr = ptr->next;
		count++;
	}
	return NULL;
}
struct Node* Delete(struct Node* head, int ind) {
	struct Node* ptr = head;
	int count = 1;
	if (ind == 1) {
		return head->next;
	}
	while (ptr->next != NULL) {
		if (count == ind - 1) {
			ptr->next = ptr->next->next;
			break;
		}
		count++;
		ptr = ptr->next;
	}
	return head;
}
void rem_dup(struct Node * start)
{
	struct Node  *i, *j, *k;
	i = createNode(0);
	j = createNode(0);
	k = createNode(0);
	i = start;
	while (i != NULL && i->next != NULL) {
		j = i;
		while (j->next != NULL) {
			if (i->data == j->next->data) {
				k = j->next;
				j->next = j->next->next;
				free(k);
			}
			else
				j = j->next;
		}
		i = i->next;
	}
}
void print_list(struct Node * head) {
	if (head == NULL) {
		printf("-1\n");
		return ;
	}
	struct Node* ptr = head;
	while (ptr != NULL) {
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}
struct Node* reverse(struct Node * head) {
	struct Node* ptr = head;
	struct Node* temp = NULL;
	while (ptr != NULL) {
		struct Node* front = ptr->next;
		ptr->next = temp;
		temp = ptr;
		ptr = front;
	}
	return temp;
}
void check_palid(struct Node * head) {
	if (head == NULL) {
		printf("-1\n");
		return ;
	}
	struct Node* slow = head;
	struct Node* fast = head;
	while (fast->next != NULL && fast->next->next != NULL) {
		fast = fast->next->next;
		slow = slow->next;
	}
	struct Node* mid = slow;
	slow->next = reverse(slow->next);

	struct Node* ptr = head;
	slow = slow->next;
	while (slow != NULL) {
		if (ptr->data == slow->data) {
			ptr = ptr->next;
			slow = slow->next;
		}
		else {
			printf("N\n");
			mid->next = reverse(mid->next);
			return;
		}
	}
	printf("Y\n");

	mid->next = reverse(mid->next);

}
int main() {
	struct Node* head = NULL;
	while (1) {
		char ch;
		scanf("%c", &ch);
		if (ch == 'a') {
			int a;
			scanf(" %d", &a);
			head = insertAtTail(head, a);
		}
		else if (ch == 'r') {
			int ind;
			scanf(" %d", &ind);
			struct Node* s = search(head, ind);
			if (s == NULL) {
				printf("-1\n");
			}
			else {
				printf("%d\n", s->data);
				head = Delete(head, ind);
			}

		}
		else if (ch == 'd') {
			if (head == NULL) {
				printf("-1\n");
				continue;
			}
			rem_dup(head);
			print_list(head);
		}
		else if (ch == 'p') {
			check_palid(head);

		}
		else if (ch == 's') {
			print_list(head);
		}
		else if (ch == 'e') {
			break;
		}
		else if (ch == ' ') {
			break;
		}
	}
}
