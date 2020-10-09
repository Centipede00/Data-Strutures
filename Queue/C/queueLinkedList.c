#include<stdlib.h>
#include<stdio.h>
struct Node{
    int data;
    struct Node *next;
};
typedef struct{
    struct Node *front;
    struct Node *rear;
    int size;
}Queue;
Queue q;
int maxSize=0;
void enqueue(Queue *q,int data){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp==NULL||maxSize>q->size-1){
        printf("stack is full,Overflow\n");
        return;
    }
    temp->data = data;
    temp->next=NULL;
    if(q->front==NULL){
        q->front=temp;
        q->rear=temp;
    }
    else{
        q->rear->next = temp;
        q->rear = temp;
    }
    maxSize++;
}
int dequeue(Queue *q){
    int x=-1;
    struct Node *temp;
    if(q->front==NULL){
        printf("queue is empty,underflow\n");
        return x;
    }
    temp = q->front;
    q->front = q->front->next;
    x = temp->data;
    free(temp);
    return x;
}
void display(){
    if(q.front==NULL){
        printf("queue is empty,underflow\n");
        return;
    }
    struct Node *temp=q.front;
    while(temp!=q.rear){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("%d\n",temp->data);
}
int main(){
    q.front==NULL;
    q.rear==NULL;
    int option,data=0;
    printf("Enter the size of the queue:");
    scanf("%d",&q.size);
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