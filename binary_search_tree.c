#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insertBST(int x,NODE root){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=x;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(root==NULL){
        return temp;
    }
    NODE prev,cur;
    prev=NULL;
    cur=root;
    while(cur!=NULL){
        prev=cur;
        if(x<cur->data)
            cur=cur->llink;
        else
            cur=cur->rlink;
        if(x<prev->data){
            prev->llink=temp;
        }
        else
            prev->rlink=temp;
        
    }
    return root;
    
}

void main(){
    NODE y;
    y=insertBST(7,y);
    y=insertBST(7,y);
    y=insertBST(8,y);
    y=insertBST(9,y);
}
