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

void show(node *l) {
    node *current = l;
    int idx = 1;
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
}
