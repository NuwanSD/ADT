#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef char TreeEntry;

typedef struct treenode
{
    TreeEntry entry;
    struct treenode *left;
    struct treenode *right;
}TreeNode;

void CreateTree(TreeNode **root)
{
    *root = NULL;
    printf("\nTree has been implemented\n");
}

int TreeEmpty(TreeNode *root)
{
   return (root == NULL) ? TRUE : FALSE;

}

TreeNode* createNode(TreeEntry entry)
{
    TreeNode *newNode = (TreeNode *)malloc(sizeof(TreeNode));
    if(newNode != NULL){
        newNode->entry = entry;
        newNode->left = NULL;
        newNode->right = NULL;
    }

    return newNode;
}

void Insert(TreeNode **root, TreeEntry entry)
{
    if(*root == NULL){
        *root = createNode(entry);
    }else{
        if(entry < (*root)->entry){
            Insert(&(*root)->left, entry);
        }else{
            Insert(&(*root)->right, entry);
        }
    }
}

void Preorder(TreeNode *root)
{
    if(root){
        printf("%c ", root->entry);

        Preorder(root->left);

        Preorder(root->right);
    }
}

void Inorder(TreeNode *root)
{
    if(root){
        Inorder(root->left);

        printf("%c ", root->entry);

        Inorder(root->right);
    }
}

void Postorder(TreeNode *root)
{
    if(root){
        Postorder(root->left);
        Postorder(root->right);
        printf("%c ", root->entry);
    }
}

int main()
{
    TreeNode *tree;

    CreateTree(&tree);

    //Insert(TreeNode **root, TreeEntry entry)
    Insert(&tree, 'A');
    Insert(&tree, 'B');
    Insert(&tree, 'C');
    Insert(&tree, 'D');
    Insert(&tree, 'E');
    Insert(&tree, 'F');
    Insert(&tree, 'G');
    Insert(&tree, 'H');
    Insert(&tree, 'I');

    printf("\nInorder Traversal: ");
    Inorder(tree);

    printf("\nPostorder Traversal: ");
    Postorder(tree);

    printf("\nPreorder Traversal: ");
    Preorder(tree);

}
