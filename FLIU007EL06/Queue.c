#include<stdio.h>
#define SIZE 5

int r,f,val;
int Queue[SIZE];

void queue_init(void);
int empty(void);
int enqueue(val);
void dequeue(void);
int front(void);
int rear(void);

void main(){

    queue_init();

    while(1){
        printf("QUEUE OPERATION INPUT:(key in -2 to break) ==> ");
        scanf("%d",&val);
        if(val>0){
        enqueue(val);
        }
        else if(val<0 && val!=-2){
            if(empty()==1){
                printf("Error -Queue is empty.\n");
            }
            else{
                 printf("Front:%d \n", front());
                 printf("Rear:%d \n", rear());
            }
        }
        else if(val == -2)
            break;
        else{
            if(empty()==1){
                printf("Error -Queue is empty.\n");
            }
            else{
            dequeue();
            }
        }
    }

}

void queue_init(void){
    r=f=-1;
}

int empty(void){
    return r==-1;
}

int enqueue(val){
    if(empty()){
        r=f=0;
    }

    else{
        r=r+1;
        if(r==SIZE)
        {
            r=0;
        }
        if(r==f)
        {
            if(r==0)
            {
                r = (SIZE-1);
            }
            else
            {
                r = (r-1);
            }
            printf("The queue is full\n");
            return 0;
        }
    }
    Queue[r]=val;
    return 1;
}

void dequeue(void){
    if(r==f){
        r=f=-1;
    }
    else{
        f=f+1;
        if(f==SIZE){
            f=0;
        }
    }
}

int front(void){
    return Queue[f];
}

int rear(void)
{
    return Queue[r];
}

