#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
struct NODE *head2;
struct NODE *head3;
void merge(struct NODE *node1,struct NODE *node2,struct NODE *node3){
    while (node1!=NULL){
        node3->info = node1->info;
        node3->next = (struct NODE*) malloc(sizeof(struct NODE));
        node1 = node1->next;
        node3 = node3->next;
    }
    while (node2!=NULL){
        node3->info = node2->info;
        node3->next = (struct NODE*) malloc(sizeof(struct NODE));
        node2 = node2->next;
        if(node2!=NULL)
        node3 = node3->next;
    }
    node3->next = NULL;
}
void create(struct NODE *node){
    int nodes;
    printf("How many nodes do you want to create?:");
    scanf("%d",&nodes);
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
    printf("Details of current Linked List is:\n");
    printf("Data present inside Nodes:\n");
    while(node->next!=NULL){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Node %d: %d\n",i,node->info);
    printf("Number of nodes present:%d\n",i);
    return i;
}
int main(){
    struct NODE *head,*node;
    struct NODE *node2,*node3;
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    printf("Enter For 1st Linked List:\n");
    create(node);


    node2 = (struct NODE*)malloc(sizeof(struct NODE));
    node2->next = NULL;
    head2 = node2;
    create(node2);
    printf("Enter For 2nd Linked List:\n");

    node3 = (struct NODE*)malloc(sizeof(struct NODE));
    node3->next = NULL;
    head3 = node3;

    merge(node,node2,node3);
    printf("Merged Linked List:\n");
    display(head3);
    return 0;
}