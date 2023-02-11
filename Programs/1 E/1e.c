//C program to demonstrate Circular Queue using Dynamic Arrays
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

bool isFull()
{
    if ( (rear + 1) % MAX_SIZE == front)
        return true;
    else
        return false;
}

bool isEmpty()
{
    if (front == -1)
        return true;
    else
        return false;
}

void enqueue(int element)
{
    if (isFull())
    {
        printf("Queue is full!\n");
        return;
    }
    if (isEmpty())
        front = rear = 0;
    else
        rear = (rear + 1) % MAX_SIZE;
    queue[rear] = element;
    printf("%d enqueued to queue\n", element);
}

void dequeue()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    int element = queue[front];
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % MAX_SIZE;
    printf("%d dequeued from queue\n", element);
}

void display()
{
    if (isEmpty())
    {
        printf("Queue is empty!\n");
        return;
    }
    printf("Queue elements are: ");
    int i = front;
    while (i != rear)
    {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", queue[i]);
}

int main()
{
    int element, choice;
    while (1)
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter an element: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}