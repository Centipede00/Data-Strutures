#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
struct NODE *head;
struct NODE *last;
void searchDelete(struct NODE *head,int data){
    struct NODE *p;
    p = head;
    int k=1;
    int found = 0;
    while(p->next!=head){
        if(p->info==data){
            delete(head,k);
            break;
        }
        p = p->next;
        k++;
    }
    if(p->info == data)
        delete(head,k);
    else
        printf("Given data is not present inside the Linked List\n");
}
void delete(struct NODE *head,int position){
    struct NODE *p,*q;
    p = head;
    int k=1;
    if(position==1){
        head = p->next;
        last->next = head;
        p->next = NULL;
        free(p);
    }
    else{
        while((p->next!=head) && (k<position)){
            k++;
            q=p;
            p = p->next;
        }
        if(p->next==head){
            q->next = head;
            last = q;
            free(p);
        }
        else{
            q->next = p->next;
            free(p);
        }
    }
    display(head);
}
void create(struct NODE *node,int nodes){
    for(int i=0;i<nodes;i++){
        printf("Enter data for Node %d:",i+1);
        scanf("%d",&node->info);
        if(i==nodes-1)
            node->next = head;
        else{
            node->next = (struct NODE*) malloc(sizeof(struct NODE));
            if(node->next == NULL)
                printf("Error\n");
            node = node->next;
        }
    }
    last = node;
}
void display(struct NODE *node){
    int i=1;
    printf("\nDetails of current Linked List is:\n");
    printf("Data present inside Nodes:\n");
    while(node->next!=head){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Node %d: %d\n",i,node->info);
    printf("Number of nodes present:%d\n",i);
}
int main(){
    struct NODE *node;
    int nodes,option,position,data;
    printf("How many nodes do you want to create?:");
    scanf("%d",&nodes);
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node,nodes);
    display(head);
    printf("\n\tOperations Available:\n");
        printf("1.deletion at the beginning of the List\n");
        printf("2.deletion at the End of the List\n");
        printf("3.deletion at a particular position\n");
        printf("4.deletion of a given node\n");
        printf("Enter any option(1-4):");
        scanf("%d",&option);
    switch (option){
        case 1: delete(node,1);
            break;

        case 2: delete(node,nodes);
            break;
        
        case 3:printf("Enter the position:");
                scanf("%d",&position);
                delete(node,position);
           break;
        
        case 4:printf("Enter the data of node,after which will be deleted:");
                scanf("%d",&data);
                searchDelete(node,data);
            break;
        default:printf("Invalid option\n");
            break;
        }
    return 0;
}