#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Queue {
    int head;
    int tail;
    int size;
    char **array;
};

// Function prototypes
struct Queue* createQueue(int size);
int isFull(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, char *item);
char* dequeue(struct Queue* queue);
int QueueFull(struct Queue* queue);
int QueueEmpty(struct Queue* queue);

int main() {
    int n;
    scanf("%d", &n);

    struct Queue* Q = createQueue(n);

    while (1) {
        char option;
        scanf(" %c", &option);
        if (option == 't') {
            break;
        }

        switch (option) {
        case 'i':
            if (!QueueFull(Q)) {
                char item[21];
                scanf(" %s", item);
                enqueue(Q, item);
            } else {
                printf("-1\n");
            }
            break;

        case 'd':
            if (!QueueEmpty(Q)) {
                char *item = dequeue(Q);
                printf("%s\n", item);
                free(item);
            } else {
                printf("-1\n");
            }
            break;

        case 'f':
            if (QueueFull(Q)) {
                printf("-1\n");
            } else {
                printf("1\n");
            }
            break;

        case 'e':
            if (QueueEmpty(Q)) {
                printf("-1\n");
            } else {
                printf("1\n");
            }
            break;
        }
    }

    // Clean up and free memory
    for (int i = 0; i < n; i++) {
        free(Q->array[i]);
    }
    free(Q->array);
    free(Q);

    return 0;
}

struct Queue* createQueue(int size) {
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->head = -1;  // Initialize head and tail to -1
    queue->tail = -1;
    queue->size = size;
    queue->array = (char**) malloc(size * sizeof(char*));
    for (int i = 0; i < size; i++) {
        queue->array[i] = (char*) malloc(21 * sizeof(char)); // Maximum string length is 20
    }
    return queue;
}

int isFull(struct Queue* queue) {
    return ((queue->tail + 1) % queue->size == queue->head);
}

int isEmpty(struct Queue* queue) {
    return (queue->head == -1);
}

void enqueue(struct Queue* queue, char *item) {
    if (!isFull(queue)) {
        if (isEmpty(queue)) {
            queue->head = 0;
        }
        queue->tail = (queue->tail + 1) % queue->size;
        strcpy(queue->array[queue->tail], item);
    }
}

char* dequeue(struct Queue* queue) {
    char *item = (char*) malloc(21 * sizeof(char));
    if (!isEmpty(queue)) {
        strcpy(item, queue->array[queue->head]);
        if (queue->head == queue->tail) {
            queue->head = -1;  // Reset head and tail to -1 for an empty queue
            queue->tail = -1;
        } else {
            queue->head = (queue->head + 1) % queue->size;
        }
    }
    return item;
}

int QueueFull(struct Queue* queue) {
    return isFull(queue);
}

int QueueEmpty(struct Queue* queue) {
    return isEmpty(queue);
}
