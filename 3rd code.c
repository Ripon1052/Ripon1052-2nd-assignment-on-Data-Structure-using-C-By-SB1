/*Write a program to create a Single Linked List and reverse it.*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create_node(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_last(struct node** head, int data) {
    struct node* newnode = create_node(data);
    if (*head == NULL) {
        *head = newnode;
    } else {
        struct node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct node* reverse_list(struct node* current) {
    if (current == NULL || current->next == NULL) {
        return current;
    }
    struct node* rest = reverse_list(current->next);
    current->next->next = current;
    current->next = NULL;
    return rest;
}

void display(struct node* head) {
    struct node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL; 
    int n, value, i;

    printf("Enter Number of Nodes: ");
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        printf("Enter Value: ");
        scanf("%d", &value); 
        insert_last(&head, value);
    }
    
    printf("Original Linked List: ");
    display(head);
    
    head = reverse_list(head);
    
    printf("Reversed Linked List: \n");
    display(head);

    return 0;
}