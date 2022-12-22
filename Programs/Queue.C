#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define MAX_SIZE 100

int main() {
    int item, choice, i;
    int arr_queue[MAX_SIZE];
    int rear = 0;
    int front = 0;
    int exit = 1;

    printf("\nSimple Queue Example - Array");
    do {
        printf("\n\n Queue Main Menu");

        printf("\n1.Insert \n2.Remove \n3.Display \nOthers to exit");
        printf("\nEnter Your Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                if (rear == MAX_SIZE)
                    printf("\n## Queue Reached Max!!");
                else {
                    printf("\nEnter The Value to be Insert : ");
                    scanf("%d", &item);
                    printf("\n## Position : %d , Insert Value  : %d ", rear + 1, item);
                    arr_queue[rear++] = item;
                }
                break;
            case 2:
                if (front == rear)
                    printf("\n## Queue is Empty!");
                else {
                    printf("\n## Position : %d , Remove Value  : %d ", front, arr_queue[front]);
                    front++;
                }
                break;
            case 3:
                printf("\n## Queue Size : %d ", rear);
                for (i = front; i < rear; i++)
                    printf("\n## Position : %d , Value  : %d ", i, arr_queue[i]);
                break;
            default:
                exit = 0;
                break;
        }
    } while (exit);

    return 0;
}