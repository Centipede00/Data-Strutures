#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
void searchinsert(struct NODE *head,int data,int nodes){
    struct NODE *p,*newNode;
    p = head;
    int k=1;
    newNode = (struct NODE*) malloc(sizeof(struct NODE));
    if(newNode == NULL){
        printf("MEMORY ERROR\n");
        return;
    }
    printf("Enter the data for new node:");
    scanf("%d",&newNode->info);
    while(p->next!=NULL){
        if(p->info==data){
            newNode->next = p->next;
            p->next = newNode;
        }
        p = p->next;
    }
    nodes++;
    display(head,nodes);
}
void insert(struct NODE *head,int position,int nodes){
    struct NODE *p,*q,*newNode;
    p = head;
    int k=1;
    newNode = (struct NODE*) malloc(sizeof(struct NODE));
    if(newNode == NULL){
        printf("MEMORY ERROR\n");
        return;
    }
    printf("Enter the data for new node:");
    scanf("%d",&newNode->info);
    if(position==1){
        newNode->next = p;
        head = newNode;
    }
    else{
        while((p->next!=NULL) && (k<position)){
            k++;
            q=p;
            p = p->next;
        }
        if(p->next==NULL){
            p->next = newNode;
            newNode->next = NULL;
        }
        else{
            q->next = newNode;
            newNode->next = p;
        }
    }
    nodes++;
    display(head,nodes);
}
void create(struct NODE *node,int nodes){
    for(int i=0;i<nodes;i++){
        printf("Enter data for Node %d:",i+1);
        scanf("%d",&node->info);
        if(i==nodes-1)
            node->next = NULL;
        else{
            node->next = (struct NODE*) malloc(sizeof(struct NODE));
            if(node->next == NULL)
                printf("Error\n");
            node = node->next;
        }
    }
}
void display(struct NODE *node,int nodes){
    int i=1;
    printf("\nDetails of current Linked List is:\n");
    printf("Number of nodes present:%d\n",nodes);
    printf("Data present inside Nodes:\n");
    while(node->next!=NULL){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Node %d: %d",i,node->info);
}
int main(){
    struct NODE *head,*node;
    int nodes,option,position,data;
    printf("How many nodes do you want to create?:");
    scanf("%d",&nodes);
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node,nodes);
    display(head,nodes);
    printf("\n\tOperations Available:\n");
        printf("1.Insertion at the beginning of the List\n");
        printf("2.Insertion at the End of the List\n");
        printf("3.Insertion at a particular position\n");
        printf("4.Insertion after a given node\n");
        printf("Enter any option(1-4):");
        scanf("%d",&option);
    switch (option){
        case 1: insert(node,1,nodes);
            nodes++;
            break;

        case 2: insert(node,nodes+1,nodes);
                nodes++;
            break;
        
        case 3:printf("Enter the position to insert:");
                scanf("%d",&position);
                insert(node,position,nodes);
                nodes++;
           break;
        
        case 4:printf("Enter the data of node,after which new node will be inserted:");
                scanf("%d",&data);
                searchinsert(node,data,nodes);
            break;
        default:printf("Invalid option\n");
            break;
        }
    return 0;
}