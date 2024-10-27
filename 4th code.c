/*Write a program to create a Single Linked List and eliminate duplicate elements from it.*/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int data) {
    struct node* newnode = (struct node*) malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert_last(struct node** head, int data) {
    struct node* newnode = create(data);
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

void remove_duplicates(struct node* head) {
    struct node* current = head;
    while (current != NULL && current->next != NULL) {
        struct node* temp = current;
        while (temp->next != NULL) {
            if (current->data == temp->next->data) {
                struct node* duplicate = temp->next;
                temp->next = temp->next->next;
                free(duplicate);
            } else {
                temp = temp->next;
            }
        }
        current = current->next;
    }
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
    int n, value;
    
    printf("Enter number of nodes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);
        insert_last(&head, value);
    }
    
    printf("Original list: ");
    display(head);
    
    remove_duplicates(head);
    
    printf("After removing duplicates: ");
    display(head);
    
    return 0;
}
