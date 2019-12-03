#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#include <assert.h>

/*
 * This Does not work
 */
void insert(node *root, int n) {
    node *new_node = (struct node_ *)malloc(sizeof(struct node_));
    if (root == NULL) {
        printf("root is NULL\n");
        root = new_node;
        return;
    }
    node *current = root;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
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

    insert(l, 3);
    printf("----------------------------------------\n");

    show(l);
}
