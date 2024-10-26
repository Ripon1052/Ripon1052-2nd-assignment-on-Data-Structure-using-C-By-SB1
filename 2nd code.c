/*Write a program to create a Single Linked List and sort it in ascending order.*/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* create_node(int data) {
    struct node *newnode = (struct node *) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_last(struct node **head, int data) {
    struct node *newnode = create_node(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void sort_list(struct node *head) {
    struct node *i, *j;
    int temp_data;

    if (head == NULL) {
        return;
    }

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp_data = i->data;
                i->data = j->data;
                j->data = temp_data;
            }
        }
    }
}

void display(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int n, value, i;

    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter Value: ");
        scanf("%d", &value);
        insert_last(&head, value);
    }

    sort_list(head);
    display(head);

    return 0;
}
