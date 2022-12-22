#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int data;
    struct node * prev;
    struct node * next;
};

struct node * search(struct node ** head , int position){

    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = * head;

    for(int i=1;i<position;i++){
        temp = temp->next;
    }

    return temp;
}

void insertFront(struct node ** head , int data){
    struct node * temp , * new_node = (struct node *) malloc(sizeof(struct node));

    temp = * head;

    new_node->data = data;
    new_node->prev = NULL;

    new_node = * head;

    if(temp == NULL){
        new_node->next = NULL;
    }
    else{
        new_node->next = temp;
        temp->prev = new_node;
    }
}

void insertLast(struct node ** head , int data){
    struct node * temp , * new_node = (struct node *) malloc(sizeof(struct node));

    temp = * head;

    new_node->data = data;
    new_node->next = NULL;

    if(temp == NULL){
        new_node->prev = NULL;
        * head = new_node;
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
}

void insertMiddle(struct node * prev , int data){
    struct node * new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = data;

    new_node->prev = prev;
    new_node->next = prev->next;
    prev->next = new_node;
}

void deleteFront(struct node ** head){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = * head;

    if(temp == NULL){
        printf("Linked list is empty\n");
    }
    else{
        printf("Data deleted is %d" , temp->data);
        printf("\n");
        * head = temp->next;
    }
}

void deleteLast(struct node ** head){
    struct node * temp = (struct node *)  malloc(sizeof(struct node));
    temp = * head;

    if(temp == NULL){
        printf("Linked list is empty!\n");
        printf("\n");
    }
    else{
        while(temp->next != NULL){
            temp = temp->next;
        }
        printf("Data deleted is %d" , temp->data);
        printf("\n");
        temp = temp->prev;
        temp->next = NULL;
    }
}

void deleteMiddle(struct node * prev){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = prev;

    if(temp == NULL){
        printf("Can't delete data!\n");
        printf("\n");
    }
    else{
        printf("Data deleted is %d" , temp->data);
        printf("\n");
        (temp->prev)->next = temp->next;
        (temp->next)->prev = temp->prev;
        temp->next = temp->prev = NULL;
    }
}

void printList(struct node ** head){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = * head;

    if(temp == NULL){
        printf("NULL\n");
    }
    else{
        while(temp != NULL){
            printf("%d - " , temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
        printf("\n");
    }
}

void printRaw(struct node ** head){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = * head;

    if(temp == NULL){
        printf("NULL\n");
    }
    else{
        printf("Prev    Data    Next\n");
        while(temp != NULL){
            printf("%d - %d - %d\n" , temp->prev ,  temp->data , temp->next);
            printf("\n");
            temp = temp->next;
        }
        printf("\n");
    }
}

int main(){

    struct node * head = NULL;

    int data , choice , position , check = true;

    printf("Enter 1 to insert data in the front\n");
    printf("Enter 2 to insert data at the last\n");
    printf("Enter 3 to insert data in the middle\n");
    printf("Enter 4 to delete data from the front\n");
    printf("Enter 5 to delete data from the last\n");
    printf("Enter 6 to delete data from the middle\n");
    printf("Enter 7 to display the doubly linked list\n");
    printf("Enter 8 to view raw linked list with address\n");
    printf("Enter 9 to EXIT!\n");

    while(check){
        printf("Enter your choice\n");
        scanf("%d" , &choice);
        printf("\n");

        switch(choice){
            case 1:
                printf("Enter the data\n");
                scanf("%d" , &data);
                printf("\n");
                insertFront(&head , data);
                break;
            case 2:
                printf("Enter the data\n");
                scanf("%d" , &data);
                printf("\n");
                insertLast(&head , data);
                break;
            case 3:
                printf("Enter the data\n");
                scanf("%d" , &data);
                printf("Enter the position to insert the data\n");
                scanf("%d" , &position);
                printf("\n");
                insertMiddle(search(&head , position) , data);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                deleteLast(&head);
                break;
            case 6:
                printf("Enter the position to delete the data\n");
                scanf("%d" , &position);
                deleteMiddle(search(&head , position));
                break;
            case 7:
                printList(&head);
                break;
            case 8:
                printRaw(&head);
                break;
            case 9:
                printf("Exiting!!\n");
                printf("\n");
                check = false;
                break;
            default:
                check = false;
                break;
        }
    }

    return 0;
}

