#include <stdio.h>
#include <conio.h>
#include <stdbool.h>
#include <stdlib.h>

struct node{
	int data;
	struct node * next;
};

struct node * insertNode(struct node * head , int data){
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
    
    newNode->data = data;
    newNode->next = NULL;

    if(head == NULL){
        newNode->next = NULL;
    }
    else{
        newNode->next = head;
    }

    head = newNode;

	return head;
}

struct node * insertLast(struct node * head , int data){
	struct node * newNode = (struct node *) malloc(sizeof(struct node));
	struct node * temp = (struct node *) malloc(sizeof(struct node));

	newNode->data = data;
	newNode->next = NULL;

	temp = head;

	if(head == NULL){
		head = newNode;
	}
	else{
		while(temp->next != NULL){
			temp = temp->next;
		}

		temp->next = newNode;
	}
	
	return head;
}

struct node * deleteNode(struct node * head){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = head;

	if(head->next == NULL || head == NULL){
		head = NULL;
	}
	else{
    	head = head->next;
		free(temp);
	}

	return head;
}

void display(struct node * head){
    struct node * temp = (struct node *) malloc(sizeof(struct node));
    temp = head;

    if(head == NULL){
        printf("Linked list is empty\n");
    }
    else{
        while(temp != NULL){
            printf("%d - " , temp->data);
            temp = temp->next;
        }
    }
}

int main(){

	struct node * head = NULL;

	int choice , data , check = true;

	printf("1. Insert at first\n");
	printf("2. Insert at last\n");
	printf("3. Delete\n");
	printf("4. Display\n");
	printf("5. Exit\n");

	while(check){
		printf("Enter the choice\n");
		scanf("%d" , &choice);
        printf("\n");

		switch(choice){
			case 1:
				printf("Enter the data\n");
				scanf("%d" , &data);

				head = insertNode(head , data);

				printf("\n");
				break;
			case 2:
				printf("Enter the data\n");
				scanf("%d" , &data);

				head = insertLast(head , data);

				printf("\n");
				break;
			case 3:
				head = deleteNode(head);

				printf("\n");
				break;
			case 4:
				display(head);
				printf("\n");
				break;
			case 5:
				check = false;
				break;
			default:
				check = false;
				break;
		}
	}

	return 0;
}