// Design, Develop and Implement a menu driven Program in C for the following operations on Binary Search Tree (BST) of Integers
// a. Create a BST of N Integers: 6, 9, 5, 2, 8, 15, 24, 14, 7, 8, 5, 2
// b. Traverse the BST in Inorder, Preorder and Post Order
// c. Search the BST for a given element (KEY) and report the appropriate message
// e. Exit

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct BST
{
    int data;
    struct BST *lc, *rc;
};
typedef struct BST node;
node *create(node *root, int a)
{
    node *temp;
    if (root == NULL)
    {
        temp = (node *)malloc(sizeof(node));
        root = temp;
        temp->data = a;
        temp->rc = temp->lc = NULL;
        return root;
    }
    else if (a < root->data)
    {
        root->lc = create(root->lc, a);
    }
    else if (a > root->data)
    {
        root->rc = create(root->rc, a);
    }
    else
        return root;
}
void search(node *root, int k)
{
    if (root == NULL)
    {
        printf("The key is not found\n");
    }
    else if (k < root->data)
    {
        search(root->lc, k);
    }
    else if (k > root->data)
    {
        search(root->rc, k);
    }
    else
        printf("The key is found\n");
}
void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d\t", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}
void postorder(node *root)
{
    if (root != NULL)
    {
        postorder(root->lc);
        postorder(root->rc);
        printf("%d\t", root->data);
    }
}
void inorder(node *root)
{
    if (root != NULL)
    {
        inorder(root->lc);
        printf("%d\t", root->data);
        inorder(root->rc);
    }
}
void traversal(node *root)
{
    int ch;
    do
    {
        printf("\n\tMenu\n1.Inorder traversal\n2.Preorder traversal\n3.Postorder traversal\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Inorder traversal:");
            inorder(root);
            break;
        case 2:
            printf("Preorder traversal:");
            preorder(root);
            break;
        case 3:
            printf("Postorder traversal:");
            postorder(root);
            break;
        default:
            break;
        }
    } while (ch >= 1 && ch <= 3);
}
void main()
{
    node *root;
    int i, n, ele, key, ch;
    root = NULL;
    while (1)
    {
        printf("\n\tMenu\n1.Create\n2.Search\n3.Traversal\n4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number of elements\n");
            scanf("%d", &n);
            printf("Enter the elements to be inserted\n");
            for (i = 0; i < n; i++)
            {
                scanf("%d", &ele);
                root = create(root, ele);
            }
            break;
        case 2:
            printf("Enter the element to be searched\n");
            scanf("%d", &key);
            search(root, key);
            break;
        case 3:
            traversal(root);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
}