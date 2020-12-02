#include<stdio.h>
#define SIZE 5

int t,val;
int stack[SIZE];


void stack_init(void);
int empty(void);
void push(val);
void pop(void);
int top(void);

void main(void){
    stack_init();

    while(1){
        printf("STACK OPERATION INPUT:(key in -2 to break) ==> ");
        scanf("%d",&val);
        if(val>0){
            push(val);
        }
        else if(val<0&&val!=-2){
            if(empty() == 1){
                printf("Error -Stack is empty.\n");
            }
            else{
                printf("%d \n", top());
            }
        }
        else if(val == -2)
            break;
        else{
            if(empty() == 1){
                printf("Error -Stack is empty.\n");
            }
            else{
                pop();
            }
        }

    }

}


void stack_init(void){
    t = -1;
}

int empty(void){
    return t == -1;
}

void push(val){
    if(stack_is_full()){
        printf("The stack is full.\n");
    }
    else{
        t=t+1;
        stack[t]=val;
    }

}

void pop(void){
    t=t-1;
}

int top(void){
    return stack[t];
}

int stack_is_full(void){
    return t == (SIZE-1);
}
