#include <stdio.h>
#include<ctype.h>

struct stack{
    char arr[30];
    int top;
};

void push(struct stack *ptr,char ele ){
    ptr->top++;
    ptr->arr[ptr->top]=ele;
}

char pop(struct stack *ptr){
    return ptr->arr[ptr->top--];
}

int prec(char s){
    switch(s){
        case '#':return 0;
                break;
        case '(':return 1;
                break;
        case '+':
        case '-':return 2;
                break;
        case '*':
        case '/':return 3;
                break;
        case '^':
        case '$':return 4;
                break;
    }
}

void infixpostfix(char infix[30],char postfix[30]){
    char symb,y;
    struct stack s;
    s.top=-1;
    push(&s,'#');
    int i=0,j=0;
    symb=infix[i];
    
    while(symb != '\0'){
        if(symb=='('){
            if(s.top!=29){
                push(&s,symb);
            }
        }
        else if(isalnum(symb)){
            postfix[j++]=symb;
        }
        else if(symb==')'){
            while(1){
                if(s.top!=-1){
                    y=pop(&s);
                    if(y=='('){
                        break;
                    }
                    postfix[j++]=y;
                }
            }
        }
        else{
            while(prec(symb)<=prec(s.arr[s.top])){
                postfix[j++]=pop(&s);
            }
            push(&s,symb);
        }
        symb=infix[++i];
    }
    
    while(1){
        y=pop(&s);
        if(y=='#'){
            break;
        }
        postfix[j++]=y;
    }
    postfix[j]='\0';
    printf("%s",postfix);
}

void main() {
   char infix[30],postfix[30];
//   infix="a+b*c$(d-e)";
    scanf("%s",infix);
   infixpostfix(infix,postfix);
}
