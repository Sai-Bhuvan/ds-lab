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
        NODE f=front;
        while(f->right!=NULL){
                f=f->right;
        }
        NODE g=getnode();
        g->info=ele;
        g->right=NULL;
        g->left=NULL;
        if(front==NULL)
                return g;
        f->right=g;
        g->left=f;
        return g;
}

NODE deleterear(NODE front){
        NODE g=front;
        NODE f;

        if(g==NULL){
                printf("no elements to delete \n");

                return NULL;
        }
        if(g->right==NULL)
                return NULL;
        while(g->right!=NULL){
                f=g;
                g=g->right;
        }
        f=g->left;
        f->right=NULL;
        freeNode(g);
        return f;
}

void disp(NODE front){
        NODE y=front;
        if(y==NULL)
                printf("no elements");

        while(y->right!=NULL){
                printf("%d ",y->info);
                y=y->right;
        }
}

void main(){
        NODE first=NULL;
        int ele,c;
        while(1){
                printf("1: insert front 2:delete front 3:insert rear 4:delete rear 5:display");
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
                        case 4:first=deleterear(first);
                               break;
                        case 5:disp(first);
                               break;
                }
        }
}



                                               
