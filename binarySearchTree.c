#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct treeNode{
    int value;
    struct treeNode *left;
    struct treeNode *right;
    
} treeNode;

treeNode *createNode(int value){
    treeNode *result = malloc(sizeof(treeNode));
    if(result != NULL){
        result->left = NULL;
        result->right = NULL;
        result->value = value;
    }
    return result;
}

void printtabs(int numtabs){
    for(int i = 0; i < numtabs; i++){
        printf("\t");
    }
}

void printTree_rec(treeNode *root, int level){
    if(root == NULL){
        printtabs(level);
        printf("Empty Tree\n");
        return;
    }
    else{
        printtabs(level);
        printf("Value = %d\n", root->value);

        printtabs(level);
        printf("left\n");
        printTree_rec(root->left, level+1);

        printtabs(level);
        printf("Right\n");
        printTree_rec(root->right, level+1);
        printtabs(level);
        printf("done\n");
    }
}

bool insertNumber(treeNode **rootptr, int value){
    treeNode *root = *rootptr;

    /*Protects from issue when adding first node*/
    if(root == NULL){
        /*tree empty*/
        (*rootptr) = createNode(value);
        return true;
    }

    /*not allowing to of the same value in this list*/
    if(value == root->value){
        printf("Value exists in tree\n");
        return false;
    }
    else if(value < root->value){
        return insertNumber(&(root->left),value);
    }
    else if (value > root->value){
        return insertNumber(&(root->right),value);
    }
    return false;
}

bool findNumber(treeNode *root, int value){
    if(root == NULL) return false;
    if(root->value == value){
        return true;
    }
    else if (value < root->value){
        findNumber((root->left), value);
    }
    else if (value > root->right){
        findNumber((root->right),value);
    }
}

int main(){
    treeNode *root = NULL;

    insertNumber(&root,35);
    insertNumber(&root,20);
    insertNumber(&root,70);
    insertNumber(&root,27);
    insertNumber(&root,45);
    insertNumber(&root,33);

    printTree_rec(root, 0);

    printf("Number 20 = %d\n",findNumber(root,20));
    printf("Number 21 = %d\n",findNumber(root,21));
    
}