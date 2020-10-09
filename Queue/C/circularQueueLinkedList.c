#include<stdio.h>
#include<stdlib.h>
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
struct Node *head;
void create(struct Node *node,int nodes){
    for(int i=0;i<nodes;i++){
        printf("Enter data for Node %d:",i+1);
        scanf("%d",&node->data);
        q.front = node;
        if(i==nodes-1){
            node->next = head;
            q.rear = node;
        }
        else{
            node->next = (struct Node*) malloc(sizeof(struct Node));
            if(node->next == NULL)
                printf("Error\n");
            node = node->next;
        }
    }
}
void enqueue(Queue *q,int data){
    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    if(temp==NULL){
        printf("No Memory inside heap\n");
        return;
    }
    temp->data = data;
    temp->next=head;
    q->rear->next = temp;
    q->rear = temp;
}
int dequeue(Queue *q){
    int x=-1;
    struct Node *temp;
    if(q->front==NULL){
        printf("queue is empty\n");
        return x;
    }
    temp = q->front;
    q->front = q->front->next;
    x = temp->data;
    free(temp);
    head = q->front;
    return x;
}
void display(){
    if(q.front==NULL){
        printf("queue is empty\n");
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
    struct Node *node;
    head = node;
    printf("Enter the size of queue:");
    scanf("%d",&q.size);
    node = (struct Node*) malloc(sizeof(struct Node));
    node->next=NULL;
    create(node,q.size);
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