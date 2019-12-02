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

void show(doubly_linked_list *l) {
    node *current = l->root;
    int idx = 1;
    while (current != NULL) {
        printf("Doubly-Linked-List elements[%d] is %d \n", idx, current->val);
        current = current->next;
        idx++;
    }
}

int main() {
    doubly_linked_list l = {};

    insert(l.root, 3);
    insert(l.root, 5);
    insert(l.root, 7);
    printf("----------------------------------------");

    show(&l);
}
