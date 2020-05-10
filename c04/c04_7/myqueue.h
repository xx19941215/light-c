#ifndef MYQUEUE_H_
#define MYQUEUE_H_

struct node
{
    struct node * next;
    int *client_socket;
};

typedef struct node node_t;

int * dequeue();
void enqueue(int *client_socket);
#endif


