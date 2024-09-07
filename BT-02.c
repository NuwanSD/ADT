#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char TreeEntry;

typedef struct treenode{
    TreeEntry entry;
    struct treenode *left;
    struct treenode *right;
}TreeNode;

void createTree(TreeNode **root){
    *root = NULL;
    printf("\nTree has been implemented\n");
}

bool TreeEmpty(TreeNode *root)
{
    return (root == NULL);
}

TreeNode *createNode(TreeEntry entry)
{
    TreeNode *nw = (TreeNode *)malloc(sizeof(TreeNode))
    if(nw !== NULL){
        nw->entry = entry;
        nw->left = NULL;
        nw->right = NULl;
    }

    return nw;
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

int main()
{
    TreeNode entry;

    TreeEntry item;

    createTree(&entry);

}
