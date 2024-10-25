#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *temp, *start = NULL, *ptr;

void insert_at_first() {
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter a number to insert: ");
    scanf("%d", &temp->data);
    temp->next = start;
    start = temp;
}

void insert_at_last() {
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter a number to insert: ");
    scanf("%d", &temp->data);
    temp->next = NULL;

    if (start == NULL) {
        start = temp;
    } else {
        ptr = start;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}

void insert_at_nth() {
    int pos, i;
    temp = (struct node*) malloc(sizeof(struct node));
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp->next = start;
        start = temp;
        printf("Enter the number to insert: ");
        scanf("%d", &temp->data);
        return;
    }

    ptr = start;
    for (i = 1; i < pos - 1; i++) {
        if (ptr == NULL) {
            printf("Position does not exist!\n");
            free(temp);
            return;
        }
        ptr = ptr->next;
    }

    printf("Enter the number to insert: ");
    scanf("%d", &temp->data);
    temp->next = ptr->next;
    ptr->next = temp;
}

void insert() {
    int ch;
    printf("\n1. Insert at first");
    printf("\n2. Insert at last");
    printf("\n3. Insert at nth");
    printf("\nYour choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            insert_at_first();
            break;
        case 2:
            insert_at_last();
            break;
        case 3:
            insert_at_nth();
            break;
        default:
            printf("Wrong choice!\n");
    }
}

void delete_first() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = start;
    start = start->next;
    printf("Deleted item = %d\n", temp->data);
    free(temp);
}

void delete_last() {
    if (start == NULL) {
        printf("List is empty!\n");
        return;
    }
    temp = start;
    if (temp->next == NULL) {
        printf("Deleted item = %d\n", temp->data);
        free(temp);
        start = NULL;
        return;
    }
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    printf("Deleted item = %d\n", temp->next->data);
    free(temp->next);
    temp->next = NULL;
}

void delete_nth() {
    int pos, i;
    printf("Enter the position: ");
    scanf("%d", &pos);

    if (pos == 1) {
        delete_first();
        return;
    }

    temp = start;
    struct node *prev = NULL;
    for (i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
        if (temp == NULL) {
            printf("Position does not exist!\n");
            return;
        }
    }
    prev->next = temp->next;
    printf("Deleted item = %d\n", temp->data);
    free(temp);
}

void delete() {
    int ch;
    printf("\n1. Delete first");
    printf("\n2. Delete last");
    printf("\n3. Delete nth");
    printf("\nYour choice: ");
    scanf("%d", &ch);
    switch (ch) {
        case 1:
            delete_first();
            break;
        case 2:
            delete_last();
            break;
        case 3:
            delete_nth();
            break;
        default:
            printf("Wrong choice!\n");
    }
}

void display() {
    if (start == NULL) {
        printf("Linked list is empty!\n");
        return;
    }
    ptr = start;
    while (ptr != NULL) {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

void create() {
    int n, item, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        temp = (struct node*) malloc(sizeof(struct node));
        printf("Enter the data to be inserted: ");
        scanf("%d", &item);
        temp->data = item;
        temp->next = NULL;

        if (start == NULL) {
            start = temp;
            ptr = temp;
        } else {
            ptr->next = temp;
            ptr = ptr->next;
        }
    }
}

int main() {
    int ch;
    create();
    while (1) {
        printf("\n1. Insert");
        printf("\n2. Delete");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Wrong choice!\n");
        }
    }
}
