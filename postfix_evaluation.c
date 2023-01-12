#include <stdio.h>
#include<ctype.h>
#include<math.h>

struct stk{
    int arr[20];
    int top;
    
};

int checkunder(int top){
    if(top==-1)
        return 0;
    return 1;
}

int checkover(int top){
    if(top==19)
        return 0;
    return 1;
    
}

void push(struct stk *s,int n){
    if(checkover(s->top)){
        s->top++;
        s->arr[s->top]=n;
    }
    else{
        printf("stack overflow");
    }
}

int pop(struct stk *s){
    if(checkunder(s->top)){
        return s->arr[s->top--];
    }
    else{
        printf("no elements to pop");
    }
}

int posteval(){
    struct stk s;
    char posh[50];
    printf("enter a valid postfix expression");
    scanf("%s",posh);
    s.top=-1;
    int a,i=0,c,b;
    char ch;
    ch=posh[i];
    while(ch != '\0'){
        if(isdigit(ch)){
            push(&s,ch-'0');
        }
        else{
            a=pop(&s);
            b=pop(&s);
            
            switch(ch){
                case '+':c=a+b;
                        break;
                case '-':c=b-a;
                        break;
                case '*':c=b*a;
                        break;
                        
                case '/':c=b/a;
                        break;
                case '$':
                case '^':c=pow(b,a);
                             break;
                            
            }
            push(&s,c);
        }
        i++;
        ch=posh[i];
        
    }
    return pop(&s);
}

void main(){
    
    printf("the asnwer for  expression is %d",posteval());
    
}
