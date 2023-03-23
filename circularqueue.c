#include<stdio.h>
#define max 20

struct cq{
        int front,rear;
        int count;
        int arr[max];
};

int overflow(int count){
        if(count==max){
                return 0;
        }
        return 1;
}

int underflow(int count){
        if(count==0){
                return 0;
        }
        return 1;
}

void insert(int ele,struct cq *q){
        if(overflow(q->count)){
                q->rear=(q->rear+1)%max;
                q->arr[q->rear]=ele;
                q->count++;
        }
        else{
                printf("queue is full\n");
        }
}
int delete(struct cq *q){
        int ele;
        if(underflow(q->count)){
                ele=q->arr[q->front];
                q->front=(q->front+1)%max;
                q->count--;
                return ele;
        }
        else
                printf("underflow");
        return -100;
}
void display(struct cq q){
        int point,i;
        if(underflow(q.count)==1){
                point=q.front;
                for(i=0;i<q.count;i++){
                        printf("%d ",q.arr[point]);
                        point =(point +1)%max;
                }
        }

        else
                printf("no elements to delete\n");
}

void main(){
        int ele,ch;
        struct cq q;
        q.front=0;
        q.rear=-1;
        q.count=0;
        while(1){
                printf("enter 1:insert 2:delete 3:display\n");
               scanf("%d",&ch);
                switch(ch){
                        case 1:printf("enter the element to be inserted \n");
                               scanf("%d",&ele);
                                insert(ele,&q);
                                break;
                        case 2:ele=delete(&q);
                               printf("element deleted is %d\n",ele);
                               break;
                        case 3:display(q);
                               break;
                }
        }

}
