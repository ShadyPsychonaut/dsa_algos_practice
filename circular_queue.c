#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue(int);
int dequeue();
int peek();
void display();

int main()
{
    int option, num;
    do
    {
        printf("\n **** MAIN MENU ****");
        printf("\n 1. Queue data");
        printf("\n 2. Dequeue data");
        printf("\n 3. Peek");
        printf("\n 4. Display the queue");
        printf("\n 5. EXIT");
        printf("\n\n Enter your choice : ");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\n Enter number to be enqueued : ");
            scanf("%d", &num);
            enqueue(num);
            break;
        case 2:
            num = dequeue();
            printf("\n The number dequeued is : %d", num);
            break;
        case 3:
            num = peek();
            printf("\n The number in the front of the queue is : %d", num);
            break;
        case 4:
            display();
            break;
        default:
            printf("\n EXITING NOW....");
        }
    } while (option < 5);
}

void enqueue(int num)
{
    if (((rear + 1) % MAX) == front)
        printf("\n OVERFLOW");
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = num;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = num;
    }
}

int dequeue()
{
    int num;
    if (front == -1 && rear == -1)
        printf("\n UNDERFLOW");
    else if (front == rear)
    {
        num = queue[front];
        front = rear = -1;
        return num;
    }
    else
    {
        num = queue[front];
        front = (front + 1) % MAX;
        return num;
    }
}

int peek()
{
    if (front == -1)
        printf("\n UNDERFLOW");
    else
        return queue[front];
}

void display()
{
    int i = front;
    if (front == -1)
        printf("\n Queue is empty");
    else
    {
        printf("\n The Queue is : ");
        while (i != rear)
        {
            printf(" %d", queue[i]);
            i = (i + 1) % MAX;
        }
        printf(" %d", queue[rear]);
    }
}