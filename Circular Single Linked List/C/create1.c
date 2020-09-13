#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    int key;
    struct NODE *next;
};
struct NODE *head;
void create(struct NODE *node,int nodes){
    for(int i=0;i<nodes;i++){
        printf("Enter data for Node %d:",i+1);
        scanf("%d",&node->info);
        node->key = i+1;
        if(i==nodes-1)
            node->next = head;
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
    printf("Details of current Circular Single Linked List is:\n");
    printf("Number of nodes present:%d\n",nodes);
    printf("Data present inside Nodes:\n");
    while(node->next!=head){
        printf("Node %d: %d\n",node->key,node->info);
        node = node->next;
        i++;
    }
    printf("Node %d: %d",node->key,node->info);
}
int main(){
    struct NODE *node;
    int nodes;
    printf("How many nodes do you want to create?:");
    scanf("%d",&nodes);
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node,nodes);
    display(head,nodes);
    return 0;
}