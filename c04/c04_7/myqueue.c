#include "myqueue.h"
#include <stdlib.h>

node_t* head = NULL;
node_t* tail = NULL;

void enqueue(int *client_socket) {
    node_t *newnode = malloc(sizeof(node_t));
    newnode->next = NULL;
    newnode->client_socket = client_socket;

    if (tail == NULL) {
        head = newnode;
    } else {
        tail->next = newnode;
    }

    tail = newnode;
}

//return NULL if the queue if empty
//returns the pointer to a clent_socket if there is one to get

int * dequeue() {
    if (head == NULL) {
        return NULL;
    } else {
        int * result = head->client_socket;
        node_t *temp = head;
        head = head->next;
        if (head == NULL) {
            tail = NULL;
        }

        free(temp);
        return result;
    }
}