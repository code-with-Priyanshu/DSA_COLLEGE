#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left,*right;
};

struct node *creation(){
    int d;
    struct node *root;
    root=NULL;
    printf("Enter the data\n");
    scanf("%d",&d);
    if(d==-1){
        return NULL;
    }
    
    root=(struct node *)malloc(sizeof(struct node));
    root->data=d;
    printf("Enter left of %d\n",d);
    root->left=creation();
    printf("Enter right of %d\n",d);
    root->right=creation();
    return root;

}
void inOrder(struct node *root){
    if(root!=NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void main(){
    struct node *root=creation();
    printf("Inorder traversal is\n");
    inOrder(root);

}
