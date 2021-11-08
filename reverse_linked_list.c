#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
struct node *create_ll(struct node *);
struct node *display(struct node *);
struct node *reverse_ll(struct node *);
struct node *delete_all(struct node *);

int main()
{
    int opt, num;
    do
    {
        printf("\n\n**** MAIN MENU ****");
        printf("\n1. Create a linked list");
        printf("\n2. Display the list");
        printf("\n3. Reverse the linked list");
        printf("\n4. Delete linked list");
        printf("\n5. EXIT");
        printf("\nEnter what u wanna do : ");
        scanf("%d", &opt);

        switch (opt)
        {
        case 1:
            head = create_ll(head);
            printf("\nLinked list created!");
            break;
        case 2:
            head = display(head);
            break;
        case 3:
            head = reverse_ll(head);
            break;
        case 4:
            head = delete_all(head);
            break;
        default:
            printf("\nEXITING...");
        }
    } while (opt != 5);
}

struct node *create_ll(struct node *head)
{
    int num;
    struct node *new_node, *ptr;
    printf("\nEnter -1 to end");
    printf("\nEnter data : ");
    scanf("%d", &num);

    while (num != -1)
    {
        new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = num;
        if (head == NULL)
        {
            head = new_node;
            ptr = new_node;
        }
        else
        {
            ptr->next = new_node;
            ptr = new_node;
        }

        printf("\nEnter data : ");
        scanf("%d", &num);
    }
    new_node->next = NULL;
    return head;
}

struct node *display(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
        printf("\nNo list found to display!");
    else
    {
        printf("\n%p", head);
        printf("\nThe list is : ");
        while (ptr != NULL)
        {
            printf("%d %p ", ptr->data, (void *)ptr);
            ptr = ptr->next;
        }
    }
    return head;
}

struct node *reverse_ll(struct node *head)
{
    struct node *current_node, *next_node, *prev_node;
    if (head == NULL)
    {
        printf("\nNo list created!");
    }
    else
    {
        prev_node = NULL;
        current_node = head;
        next_node = head;

        while (current_node != NULL)
        {
            next_node = next_node->next;
            current_node->next = prev_node;
            prev_node = current_node;
            current_node = next_node;
        }

        head = prev_node;
        printf("\nLinked list reversed");
        return head;
    }
}

struct node *delete_all(struct node *head)
{
    struct node *ptr;
    if (head == NULL)
        printf("\nList not created ;)");
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            ptr = ptr->next;
            free(head);
            head = ptr;
        }
        printf("\nList deleted!");
        return head;

        // preptr = head;
        // while (preptr->next != NULL)
        // {
        //     ptr = preptr->next;
        //     free(preptr);
        //     preptr = ptr;
        // }
        // free(ptr);
        // return NULL;
    }
}