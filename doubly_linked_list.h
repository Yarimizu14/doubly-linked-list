#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <stdio.h>

typedef struct node_ {
    int val;
    struct node_ *next;
    struct node_ *prev;
} node;

void insert(node **root, int n);
int size(node *root);

#endif
