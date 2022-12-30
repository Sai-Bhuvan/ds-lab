include<stdio.h>
#define max 20
struct queue{
        int front,rear;
        int arr[max];
};
int full(int rear){
        if(rear==max-1){
                return 1;
        }
        return 0;
}
int isempty(int front ,int rear){
        if(rear<front){
                return 1;
        }
        return 0;
}
void insert(int ele,struct queue *s){
        if(full(s->rear)==0){
                s->rear++;
                s->arr[s->rear]=ele;
        }
        else
                printf("the queue is full\n");
}
int delete(struct queue *s){
        int ele;
        if(isempty(s->front,s->rear)==0){
                ele=s->arr[s->front];
                s->front++;
                return ele;
        }
        else
                printf("no elements to return\n");
        return -100;
}
void display(struct queue *s){
        int i;
        if(isempty(s->front,s->rear)==0){
                for(i=s->front;i<=s->rear;i++){
                        printf("%d ",s->arr[i]);
                }
        }
        else{
                printf("no element to display\n");
        }
}
void main(){
        struct queue s;
        int ele,ch;
        s.front=0;
        s.rear=-1;
        while(1){
               printf("enter 1:insert 2:delete 3:display\n");
               scanf("%d",&ch);
                switch(ch){
                        case 1:printf("enter the element to be inserted \n");
                               scanf("%d",&ele);
                                insert(ele,&s);
                                break;
                        case 2:ele=delete(&s);
                               printf("element deleted is %d\n",ele);
                               break;
                        case 3:display(&s);
                }
        }

}

