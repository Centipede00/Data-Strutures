#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
struct NODE *head;
void insert(struct NODE *,int);
int display(struct NODE *);
void searchInsert(struct NODE *node,int data){
    int found=0,k=1;
    while (node!=NULL){
        if(node->info==data){
            insert(head,k+1);
            found = 1;
        }
        node = node->next;
        k++;
    }
    if(found==0){
        printf("%d is not present inside the Linked List\n",data);
    }
}
void insert(struct NODE *node,int position){
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
        if((p->next==NULL)&&(k<position)){
            p->next = newNode;
            newNode->next = NULL;
        }
        else{
            q->next = newNode;
            newNode->next = p;
        }
    }
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
int display(struct NODE *node){
    int i=1;
    printf("\nDetails of current Linked List is:\n");
    printf("Data present inside Nodes:\n");
    while(node!=NULL){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Number of nodes present in single Linked List:%d\n",i-1);
    return i;
}
int main(){
    struct NODE *node;
    int nodes,option=0,position,data;
    printf("How many nodes do you want to create?:");
    scanf("%d",&nodes);
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node,nodes);
    nodes = display(head);
    while (option!=5){
        printf("\n\tOperations Available:\n");
        printf("1.Insertion at the beginning of the List\n");
        printf("2.Insertion at the End of the List\n");
        printf("3.Insertion at a particular position\n");
        printf("4.Insertion after a given node\n");
        printf("5.Quit\n");
        printf("Enter any option(1-4):");
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
        nodes = display(head);
        system("pause");
    }
    return 0;
}