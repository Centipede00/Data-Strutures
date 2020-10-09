#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int front;
    int rear;
    int *arr;
};
struct Queue q;
void enqueue(struct Queue *q,int data){
    if((q->rear+1)%q->size==q->front){
        printf("Queue is full,No data can be inserted.\n");
        return;
    }
    q->rear= (q->rear+1)%q->size;
    q->arr[q->rear] = data;
}
int dequeue(struct Queue *q){
    int x =-1;
    if(q->rear==q->front){
        printf("Queue is Empty,No data can be deleted.\n");
        return x;
    }
    q->front = (q->front+1)%q->size;
    x = q->arr[q->front];
    return x;
}
void display(){
    if(q.front==q.rear){
        printf("No elements present inside queue.\n");
        return;
    }
    int i = q.front+1;
    do{
        printf("%d ",q.arr[i]);
        i = (i+1)%q.size;
    } while (i!=(q.rear+1)%q.size);
    
    printf("\n");
}
int main(){
    printf("Enter the size of queue:");
    scanf("%d",&q.size);
    q.arr = (int *) malloc(q.size*sizeof(int));
    q.front=0;
    q.rear=0;
    int option,data=0;
    while(1>0){
        printf("\tOptions Available:\n");
        printf("1.Insert an element into queue.\n");
        printf("2.delete an element from queue.\n");
        printf("3.display the queue.\n");
        printf("4.Exit/Quit.\n");
        printf("Enter any options between 1-4:");
        scanf("%d",&option);
        if(option==1){
            printf("Enter the data:");
            scanf("%d",&data);
            enqueue(&q,data);
            system("pause");
        }
        else if(option==2){
            data = dequeue(&q);
            if(data!=-1)
                printf("%d has be deleted from queue.\n",data);
            system("pause");
        }
        else if(option==3){
            display();
            system("pause");
        }
        else if(option==4){
            break;
        }
        else{
            printf("Invalid option\n");
            printf("Please try again\n");
        }
    }
    return 0;
}