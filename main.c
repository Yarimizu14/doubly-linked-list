#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include <assert.h>

void insert(node **root, int n) {
    if (*root == NULL) {
        printf("root is NULL\n");
        *root = (struct node_ *)malloc(sizeof(struct node_));
        **root = (node){n};
        return;
    }
    node *current = *root;
    node *new_node = (struct node_ *)malloc(sizeof(struct node_));
    *new_node = (node){n};
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
}

void insert_after(node *target, int n) {
    node *new_node = (struct node_ *)malloc(sizeof(struct node_));
    *new_node = (node){n};

    node *next = target->next;
    target->next = new_node;

    new_node->next = next;
    new_node->prev = target;
}

int size(node *root) {
    int count = 1;
    node *current = root;
    while (current != NULL) {
        current = current->next;
        count++;
    }
    return count;
}

node *get(node *root, int index) {
    assert(index >= 0);
    int idx = 0;
    node *current = root;
    while (current != NULL) {
        if (idx == index) {
            return current;
        }
        current = current->next;
        idx++;
    }
    return NULL;
}

void show(node *l) {
    node *current = l;
    int idx = 0;
    while (current != NULL) {
        printf("Doubly-Linked-List elements[%d] is %d \n", idx, current->val);
        current = current->next;
        idx++;
    }
}

int main() {
    node *l = NULL;

    insert(&l, 3);
    insert(&l, 2);
    insert(&l, 5);
    insert(&l, 4);
    printf("----------------------------------------\n");

    show(l);
    int s = size(l);
    printf("size of l is %d\n", s);

    node *t = get(l, 1);
    printf("target node val is %d\n", t->val);

    insert_after(t, 8);
    printf("----------------------------------------\n");
    show(l);
}
