#include <stdio.h>
#include <stdlib.h>

/* Tree düðüm yapýsý */
struct Node {
    char data;
    struct Node *left;
    struct Node *right;
};

/* Yeni düðüm oluþturma */
struct Node* newNode(char data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Inorder traversal (ifade yazdýrma) */
void inorder(struct Node* root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%c ", root->data);
        inorder(root->right);
    }
}

int main()
{
    /*
          =
        /   \
       a     +
            / \
           b   *
              / \
             c   2
    */

    struct Node* root = newNode('=');

    root->left = newNode('a');
    root->right = newNode('+');

    root->right->left = newNode('b');
    root->right->right = newNode('*');

    root->right->right->left = newNode('c');
    root->right->right->right = newNode('2');

    printf("Expression Tree (Inorder): ");
    inorder(root);

    return 0;
}
