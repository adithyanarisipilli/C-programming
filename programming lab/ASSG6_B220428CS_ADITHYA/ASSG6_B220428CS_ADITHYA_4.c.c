#include <stdio.h>
#include <stdlib.h>
struct queue{
    int head, tail;
    int *arr;
};
typedef struct queue queue;

int isFull(queue *q, int size) {
    if(q->head == q->tail + 1 || (q->head == 0 && (q->tail == size-1))) {
        return 1;
    }
    return 0;
}
int isEmpty(queue *q) {
    if(q->tail == -1) {
        return 1;
    }
    return 0;
}
void enqueue(queue *q, int val, int n) {
    if(isFull(q, n)) {
        return;
    }
    if(q->tail == -1) {
        q->tail = 0;
        q->head = 0;
    } else {
        q->tail = (q->tail + 1) % n;
    }
    q->arr[q->tail] = val;
    
}

void dequeue(queue *q, int n) {
    if(isEmpty(q)) {
        return;
    }
    if(q->tail == q->head) {
        q->tail = -1;
        q->head = -1;
        return;
    }
    q->head = (q->head + 1) % n;
}
void reverse(queue *q, int n, int k) {
    int arr[k];
    for(int i = k-1; i >= 0; i--) {
        arr[i] = q->arr[q->head];
        dequeue(q, n);
    }
    for(int i = 0; i < k; i++) {
        enqueue(q, arr[i], n);
    }
    for(int i = 0; i < n-k; i++) {
        int temp = q->arr[q->head];
        dequeue(q, n);
        enqueue(q, temp, n);
    }
}
int main(int argc, char const *argv[])
{
    int n, k, val;
    scanf("%d %d", &n, &k);
    queue q;
    q.head = -1;
    q.tail = -1;
    q.arr = (int *) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        enqueue(&q, val, n);
    }
    reverse(&q, n, k);
    for(int i = 0; i < n-1; i++) {
        printf("%d ", q.arr[i]);
    }
    printf("%d", q.arr[q.tail]);
    return 0;
}
