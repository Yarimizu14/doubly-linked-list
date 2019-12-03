#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>

typedef struct node_ {
    int val;
    struct node_ *next;
    struct node_ *prev;
} node;

void insert(node **root, int n);
void insert_after(node *target, int n);
int size(node *root);
node *get(node *root, int index);

#endif
