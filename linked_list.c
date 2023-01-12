#include<stdio.h>
#include<stdlib.h>
struct node{
        int info;
        struct node *next;
};
typedef struct node *node;


node getnode(){
        node p;
        p=(node)malloc(sizeof(struct node));
        return p;
}

void freenode(node p){
        free(p);
}

node insertFront(node p,int ele){
        node q;
        q=getnode();
        q->info=ele;
        q->next=p;
        return q;
}

node deleteFront(node p){
        node q=p;
        if(p==NULL){
                printf("delete not possible");
                return NULL;
        }
        printf("%d",q->info);
        p=p->next;
        freenode(q);
        return p;
}

void display(node p){
        node q=p;
        while(q!=NULL){
                printf("%d ",q->info);
                q=q->next;
        }
}

int search(node p,int ele){
        int count =0;
        if(p==NULL){
                printf("no elements to search\n");
                return -1;
        }
        node s=p;while(s!=NULL){
                if(s->info==ele){
                        count++;
                        return count;
                }
                s=s->next;
                count++;
        }
        if(s==NULL){
                printf("element not found \n");
                return -1;
        }
        return count;
}

node insertpos(node p,int pos,int ele){
        if(p==NULL){
                node q=getnode();
                q->next=NULL;
                q->info=ele;
                return q;
        }
        else if(pos==1){
                p=insertFront(p,ele);
                return p;
        }
        else{
                node s=p;
                for(int i=0;i<pos-1;i++){
                        s=s->next;
                        if(s==NULL){
                                printf("pos>size of list \n");
                                p=insertFront(p,ele);
                                return p;
                        }
                        node q=getnode();
                        q->info=ele;
                        q->next=s->next;
                        s->next=q;
                        return p;
                }
        }
}
ode deletepos(node p,int pos){
        if(p==NULL){
                printf("no lements to delete \n");
                return p;
        }
        else if(pos==1){
                p=deleteFront(p);
                        return p;
        }
        else{
                node prev,s;
                s=p;
                for(int i=0;i<pos;i++){
                        prev=s;
                        s=s->next;
                        if(s==NULL){
                                printf("pos>size of list deletion not possible \n");
                                return p;
                        }
                        prev->next=s->next;
                        freenode(s);
                        return p;
                }
        }
}

node insertrear(node p,int ele){
        node q;
        q=getnode();
        q->info=ele;
        q->next=NULL;
        if(p==NULL){
                p=q;
                return p;
        }
        node s=p;
        while(s->next!=NULL){
                s=s->next;
        }
                s->next=q;
                return p;
}
node deleterear(node p){
        if(p!=NULL)
                return NULL;
        node q=p;
        node prev;
        if(q->next==NULL){
                freenode(q);
                return NULL;
        }
        while(q->next!=NULL){
                prev=q;
                q=q->next;
        }
        prev->next=NULL;
        freenode(q);
        return p;
}


void main(){
        node p=NULL,q;
        int ele,ch,pos;
        while(1){
                printf("enter 1:insert 2:delete 3:display 4:search 5:insert at pos 6:delete at pos 7:delete at rear 8:insert at rear\n");
                scanf("%d",&ch);
                switch(ch){
                        case 1:printf("enter the element to be inserted \n");
                               scanf("%d",&ele);
                                p=insertFront(p,ele);
                                break;
                        case 2:p=deleteFront(p);
                               break;
                        case 3:display(p);
                               break;
                        case 4:printf("enter the element to be searched \n");
                               scanf("%d",&ele);
                               int count;
                               count=search(p,ele);
                               if(count!=-1){
                                       printf("%d\n",count);
                                }
                                break;
                        case 5:printf("enter the element to be inserted \n");
                               scanf("%d",&ele);
                               printf("enter the position at which u want to insert \n");
                               scanf("%d",&pos);
                                p=insertpos(p,pos,ele);
                               break;
                        case 6:printf("enter the position at which u want to delete  \n");
                               scanf("%d",&pos);
                               p=deletepos(p,pos);
                               break;
                        case 7:q=deleterear(p);
                               printf("element deleted is %d\n",q->info);
                               break;
                        case 8:printf("enter the element to be inserted \n");
                               scanf("%d",&ele);
                               insertrear(p,ele);
                               break;

                }
        }
}

