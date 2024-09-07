#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode* createNode(int data)
{
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
};

struct TreeNode* insertNode(struct TreeNode* root, int data)
{
    if(root == NULL){
        return createNode(data);
    }

    if(data < root->data){
        root->left = insertNode(root->left, data);
    }else if(data > root->data){
        root->right = insertNode(root->right, data);
    }

    return root;
};

void inOrderTraversal(struct TreeNode* root)
{
    if(root != NULL){
        inOrderTraversal(root->left);
        printf(" %d ", root->data);
        inOrderTraversal(root->right);
    }
}

int main()
{

    struct TreeNode* root = NULL;

    root = insertNode(root, 50);

    insertNode(root, 30);
    insertNode(root, 70);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 60);
    insertNode(root, 80);


    // Print in-order traversal of the tree
    printf("In-order Traversal: ");
    inOrderTraversal(root);
    printf("\n");

}

