#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
int nodes;

void insert(struct Node *,int);
void searchInsert(struct Node*,int);
void display(struct Node*);
void create(struct Node *,int);

void searchInsert(struct Node *node,int data){
    int found=0,k=1;
    while(node->next!=NULL){
        if(node->info==data){
            insert(node,k+1);
            found = 1;
            break;
        }
        node = node->next;
        k++;
    }
    if((node->info==data)&&(found==0)){       //if data is present in last node
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
    int k=1;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    if(newNode == NULL){
        printf("MEMORY ERROR\n");
        return;
    }
    printf("Enter the data for new node:");
    scanf("%d",&newNode->info);
    if(position==1){
        newNode->next = p;
        newNode->prev = NULL;
        p->prev = newNode;
        start = newNode;
    }
    else{
        while((p->next!=NULL) && (k<position)){
            k++;
            q=p;
            p = p->next;
        }
        if((p->next==NULL)&&(k<position)){
            p->next = newNode;
            newNode->prev = p;
            newNode->next = NULL;
        }
        else{
            newNode->next = p;
            newNode->prev = q;
            q->next = newNode;
            p->prev = newNode;
        }
    }
    nodes++;
}
void create(struct Node *node,int nodes){
    int j=1;
    for (int i = 0; i < nodes; i++){
        printf("Enter data for node %d:",j);
        scanf("%d",&node->info);
        node->next = NULL;
        j++;
        if(i+1!=nodes){
            node->next = (struct Node*) malloc(1 * sizeof(struct Node));
            node->next->prev = node;
            if(node->next == NULL)
                printf("Error\n");
            node = node->next;
        }
    }
}
void display(struct Node *node){
    int i=1;
    printf("\n");
    printf("printing from starting of double linked list: \n");
    while(node->next!=NULL){
        printf("Data at node %d is %d \n",i,node->info);
        i++;
        node = node->next;
    }
    printf("Data at node %d is %d \n",i,node->info);
    printf("Nodes present:%d\n",nodes);
    printf("\n");
    printf("printing from Last of double linked list: \n");
    while(node->prev!=NULL){
        printf("Data at node %d is %d \n",i,node->info);
        i--;
        node = node->prev;
    }
    printf("Data at node %d is %d \n",i,node->info);
    printf("Nodes present:%d\n",nodes);

}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    node->prev = NULL;
    printf("How many node do you want to enter?:");
    scanf("%d",&nodes);
    create(node,nodes);
    start = node;
    display(start);
    int option,position,data;
    while (option!=5){
        printf("\n\tOperations Available:\n");
        printf("1.Insertion at the beginning of the List\n");
        printf("2.Insertion at the End of the List\n");
        printf("3.Insertion at a particular position\n");
        printf("4.Insertion after a given node\n");
        printf("5.Quit\n");
        printf("Enter any option(1-5):");
        scanf("%d",&option);
        if(option == 1){
            insert(node,1);
        }
        else if(option ==2){
            insert(node,nodes+1);
        }
        else if(option==3){
            printf("Enter the position to insert:");
            scanf("%d",&position);
            if(position>nodes+1)
                printf("Invalid Position,Postion exceeds than node numbers.\n");
            else
                insert(node,position);
        }
        else if(option==4){
            printf("Enter the data of node,after which new node will be inserted:");
            scanf("%d",&data);
            searchInsert(node,data);
        }
        else if(option == 5){
            break;
        }
        else{
            printf("Invalid Option\n");
        }
        display(start);
        system("pause");
    }
    return 0;
}