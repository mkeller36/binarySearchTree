#include <stdio.h>
#include <stdlib.h>

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

int main(){
    treeNode *n1 = createNode(43);
    treeNode *n2 = createNode(93);
    treeNode *n3 = createNode(72);
    treeNode *n4 = createNode(39);
    treeNode *n5 = createNode(93);
    treeNode *n6 = createNode(57);
    treeNode *n7 = createNode(64);
    treeNode *n8 = createNode(27);

    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5; 
    n3->left = n6;
    n3->right = n7;
    n4->left = n8;

    printTree_rec(n1, 0);
    
    free(n1);
    free(n2);
    free(n3);
    free(n4);
    free(n5);
    free(n6);
    free(n7);
    free(n8);
}