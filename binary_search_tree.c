#include <stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *llink;
    struct node *rlink;
};

typedef struct node *NODE;

NODE insertBST(NODE root,int x){
    NODE temp=(NODE)malloc(sizeof(struct node));
    temp->data=x;
    temp->rlink=NULL;
    temp->llink=NULL;
    if(root==NULL){
        return temp;
    }
    else{
        NODE p=root;
        while(1){
           if (x > p->data)
            {
                if (p->rlink == NULL)
                {
                    p->rlink = temp;
                    break;
                }
                p = p->rlink;
            }
            else
            {
                if (p->llink == NULL)
                {
                    p->llink = temp;
                    break;
                }
                p = p->llink;
            }
            
        }
    return root;
    }
    return root;
    
}

void inorder(NODE root)
{
    if (root == NULL)
        return;
    else
    {
        inorder(root->llink);
        printf("%d\t", root->data);
        inorder(root->rlink);
    }
}
void preorder(NODE root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->llink);
    preorder(root->rlink);
}
void postorder(NODE root)
{
    if (root == NULL)
        return;
    postorder(root->llink);
    postorder(root->rlink);
    printf("%d\t", root->data);
}

void search(NODE root,int ele){
    NODE p=root;
    
    while(p!=NULL){
        if(p->data==ele){
            printf("ele found");
            return;
        }
        
        if(ele>p->data){
            if(p->rlink==NULL){
                printf("ele not found");
                return ;
            }
            p=p->rlink;
        }
        else{
            if(p->llink==NULL){
                printf("ele not found ");
                return ;
            }
            p=p->llink;
        }
    }
}
void main()
{
    int a, ele;
    NODE root;
    while (1)
    {
        printf("Enter 1. Insert\n2. Inorder\n3. Preorder\n4. Postorder \n 5:search\n");
        printf("->\t");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element\n");
            scanf("%d", &ele);
            root = insertBST(root, ele);
            break;
        case 2:
            inorder(root);
            printf("\n");
            break;
        case 3:
            preorder(root);
            printf("\n");
            break;
        case 4:
            postorder(root);
            printf("\n");
            break;

        case 5:
            search(root,5);
            break;
            
        default:
            break;
        }
    }
}
