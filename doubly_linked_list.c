#include<stdio.h>
#include<stdlib.h>
struct node{
        int info;
        struct node *left;
        struct node *right;
};
typedef struct node *NODE;
NODE getnode(){
        NODE q=(NODE)malloc(sizeof(struct node));
        return q;
}
void freeNode(NODE q){
        free(q);
}
NODE insertfront(NODE first,int ele){
        NODE q;
        q=getnode();
        q->info=ele;
        q->left=NULL;
        q->right=NULL;
        if(first==NULL)
                return q;
        first->left=q;
        q->right=first;
        return q;
}

NODE deletef(NODE front){
        if(front==NULL){
                printf("no elements to delete\n");
                return NULL;
        }
        if(front->right==NULL){
                printf("%d  was deleted \n",front->info);
                return NULL;
        }
        NODE p=front;
         printf("%d  was deleted \n",front->info);

        p=p->right;
        p->left=NULL;
        freeNode(front);
        return p;
}

NODE insertrear(NODE front,int ele){
        NODE f=front,q;
        NODE g=getnode();
        g->info=ele;
        g->right=NULL;
        g->left=NULL;
        if(front==NULL)
                return g;
        if(front->right==NULL){
                q=insertfront(front,ele);
                return q;
        }
        while(f->right!=NULL){
                f=f->right;
        }
        // f=f->right;
        f->right=g;
        g->left=f;
        return front;
}

NODE deleteRear(NODE p)
{
    NODE q = p;
    if (q == NULL)
    {
        return NULL;
    }
    else if (q->right == NULL && q->left == NULL)
    {
        printf("Deleted element is %d\n", q->info);
        freeNode(q);
        return p;
    }
    else
    {
        while (q->right->right != NULL)
        {

            q = q->right;
        }
        NODE r = q->right;
        printf("Deleted element is %d\n", r->info);        
        q->right = NULL;
        freeNode(r);
        return p;
    }
    return p;
}
void disp(NODE front){
        NODE y=front;
        if(y==NULL){
        
                printf("no elements");
                return;
        }
        if(y->right ==NULL){
            printf("%d",y->info);
            return;
        }
        while(y!=NULL){
                printf("%d ",y->info);
                y=y->right;
        }
        
}

int search(NODE p, int ele)
{
        NODE s = p;
        int count = 0;
        while(s!=NULL)
        {
                if(s->info == ele)
                {
                        count++;
                        return count;
                }
                count++;
                s=s->right;
        }
        if(s==NULL)
                return -1;
}

// order of insertion
void dispinsertion(node front){
    node q=front;
    while(q->right!=NULL)
        q=q->right;
    while(q->left!=NULL){
        printf("%d ",q->info);
        q=q->left;
    }
    printf("\n");
}

// reverse order of insertion
void dispreverse(node front){
    node q=front;
    while(q!=NULL){
        printf("%d ",q->info);
        q=q->right;
    }
        
}

void main(){
        NODE first=NULL;
        int ele,c,y;
        while(1){
                printf("1: insert front 2:delete front 3:insert rear 4:delete rear 5:search 6:display");
                scanf("%d",&c);
                switch(c){
                        case 1:printf("enter ele to insert \n");
                                scanf("%d",&ele);
                                first=insertfront(first,ele);
                                break;
                        case 2:first=deletef(first);
                               break;
                        case 3:printf("enter ele to insert \n");
                                scanf("%d",&ele);
                                first=insertrear(first,ele);
                                break;
                        case 4:first=deleteRear(first);
                               break;
                        case 5:printf("enter ele to search \n");
                                scanf("%d",&ele);
                                y=search(first,ele);
                                printf("%d \n",y);
                        case 6:disp(first);
                               break;
                }
        }
}                                              
