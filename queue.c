#include <stdio.h>
#define MAX 50

int queue[MAX];
int rear = -1;
int front = -1;

void insert();
void delet();
void display();

int main() {
    int choice;
    while (1) {
        printf("1.Insert\t2.Delete\t3.Display\t4.Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: 
                insert();
                break;
            case 2: 
                delet();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default: 
                printf("Wrong choice\n");
                break;
        }
    }
    return 0;
}

void insert() {
    int new_element;
    if (rear == MAX - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    printf("Enter the new element: ");
    scanf("%d", &new_element);
    rear++;
    queue[rear] = new_element;
}

void delet() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return;
    }
    printf("%d has been deleted\n", queue[front]);
    front++;
    if (front > rear) {
        front = rear = -1;
    }
}

void display() {
    int i;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("The elements in the queue are:\n");
    for (i = front; i <= rear; i++) {
        printf("%d\t", queue[i]);
    }
    printf("\n");
}
