#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
struct Node *last;
void searchinsert(struct Node *node,int data){
    int found,k=1;
    while(node->next!=start){
        if(node->info==data){
            insert(node,k+1);
            found = 1;
            break;
        }
        found = 0;
        node = node->next;
        k++;
    }
    if((found != 1) && (node->info==data)){
            insert(node,k+1);
            found = 1;
    }
    else if(found == 0 ){
        printf("%d is not present inside Double Linked List\n",data);
    }
}
void insert(struct Node *node,int position){
    struct Node *p,*q,*newNode;
    p = start;
    int found,k=1;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("MEMORY ERROR\n");
        return;
    }
    printf("Enter the data for new node:");
    scanf("%d",&newNode->info);
    if(position==1){
        newNode->next = p;
        newNode->prev = last;
        last->next = newNode;
        p->prev = newNode;
        start = newNode;
        found =1;
    }
    else{
        while((p->next!=start) && (k<position)){
            k++;
            q=p;
            p = p->next;
        }
        if(p->next==start){
            p->next = newNode;
            newNode->prev = p;
            newNode->next = start;
            start->prev = newNode;
            last = newNode;
            found = 1;
        }
        else{
            newNode->next = p;
            newNode->prev = q;
            q->next = newNode;
            p->prev = newNode;
            found = 1;
        }
    }
    if(found!=1){
        printf("%d position exceeds the size of Double Linked List size\n",position);
    }
    else
    k = display(start);
}
void create(struct Node *node){
    int j=1;
    int value;

    printf("How many node do you want to enter?:");
    scanf("%d",&value);

        for (int i = 0; i < value; i++){
            printf("Enter data for node %d:",j);
            scanf("%d",&node->info);
            node->next = NULL;
            j++;
            if(i+1!=value){
                node->next = (struct Node*) malloc(1 * sizeof(struct Node));
                node->next->prev = node;
                if(node->next == NULL)
                    printf("Error\n");
                node = node->next;
            }
        }
        last = node;
        node->next = start;
        node = node->next;
        node->prev = last;
}
int display(struct Node *node){
    int i=1;
    printf("\n");
    printf("printing from starting of double linked list: \n");
    while(node->next!=start){
        printf("Data at node %d is %d \n",i,node->info);
        i++;
        node = node->next;
    }
    printf("Data at node %d is %d \n",i,node->info);
    printf("Nodes present:%d\n",i);
    printf("\n");
    int j=1;
    printf("printing from Last of double linked list: \n");
    while(node->prev!=last){
        printf("Data at node %d is %d \n",i,node->info);
        i--;
        j++;
        node = node->prev;
    }
    printf("Data at node %d is %d \n",i,node->info);
    printf("Nodes present:%d\n",j);

    return j;
}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    start = node;
    node->prev = NULL;
    create(node);
    int nodes = display(start);
    int option,position,data;
    printf("\n\tOperations Available:\n");
        printf("1.Insertion at the beginning of the List\n");
        printf("2.Insertion at the End of the List\n");
        printf("3.Insertion at a particular position\n");
        printf("4.Insertion after a given node\n");
        printf("Enter any option(1-4):");
        scanf("%d",&option);
    switch (option){
        case 1: insert(node,1);
            break;

        case 2:
            insert(node,nodes+1);
            break;
        
        case 3:printf("Enter the position to insert:");
                scanf("%d",&position);
                insert(node,position);
                break;
        
        case 4:printf("Enter the data of node,after which new node will be inserted:");
                scanf("%d",&data);
                searchinsert(node,data);
            break;
        default:printf("Invalid option\n");
            break;
        }
    return 0;
}