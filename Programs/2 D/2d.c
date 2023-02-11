//C Program to determine if given two trees are identical or not.
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

int areIdentical(struct node *a, struct node *b)
{
    if (a == NULL && b == NULL)
        return 1;

    if (a != NULL && b != NULL)
    {
        return
        (
            a->data == b->data &&
            areIdentical(a->left, b->left) &&
            areIdentical(a->right, b->right)
        );
    }

    return 0;
}

int main()
{
    struct node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->left->left  = newNode(4);
    root1->left->right = newNode(5);

    struct node *root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);

    if(areIdentical(root1, root2))
        printf("Both tree are identical.");
    else
        printf("Trees are not identical.");

    return 0;
}
