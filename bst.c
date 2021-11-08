#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>

struct node
{
    int key;
    char *name;

    struct node *leftChild;
    struct node *rightChild;
};

struct node *tree;
void create_tree(struct node *);
struct node *insertNode(struct node *, int, char *);
void inOrderTraverseTree(struct node *);
struct node *findNode(struct node *, int);

void main()
{
    create_tree(tree);

    tree = insertNode(tree, 50, "Boss");
    tree = insertNode(tree, 25, "Programmer");
    tree = insertNode(tree, 15, "Intern");
    tree = insertNode(tree, 30, "Security head");
    tree = insertNode(tree, 75, "Sales manager");
    tree = insertNode(tree, 85, "Salesman");

    inOrderTraverseTree(tree);

    struct node *keyNode = findNode(tree, 15);

    printf("\n\n%s has a key %d", keyNode->name, keyNode->key);
}

void create_tree(struct node *tree)
{
    tree = NULL;
}

struct node *insertNode(struct node *tree, int val, char *post)
{
    struct node *newNode, *parentptr, *nodeptr;
    newNode = (struct node *)malloc(sizeof(struct node));
    newNode->name = malloc(strlen(post) + 1);
    newNode->key = val;
    strcpy(newNode->name, post);
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;

    if (tree == NULL)
    {
        tree = newNode;
        tree->leftChild = NULL;
        tree->rightChild = NULL;
    }
    else
    {
        parentptr = NULL;
        nodeptr = tree;
        while (nodeptr != NULL)
        {
            parentptr = nodeptr;
            if (val < nodeptr->key)
                nodeptr = nodeptr->leftChild;
            else
                nodeptr = nodeptr->rightChild;
        }
        if (val < parentptr->key)
            parentptr->leftChild = newNode;
        else
            parentptr->rightChild = newNode;
    }
    return tree;
}

void inOrderTraverseTree(struct node *tree)
{
    if (tree != NULL)
    {
        inOrderTraverseTree(tree->leftChild);
        printf("\n%s has a key %d", tree->name, tree->key);
        inOrderTraverseTree(tree->rightChild);
    }
}

struct node *findNode(struct node *tree, int key)
{
    struct node *focusNode = tree;
    while (focusNode->key != key)
    {
        if (key < focusNode->key)
            focusNode = focusNode->leftChild;
        else
            focusNode = focusNode->rightChild;

        if (focusNode == NULL)
            return NULL;
    }
    return focusNode;
}