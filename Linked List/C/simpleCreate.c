#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
void create(struct NODE *node,int nodes){
    for(int i=0;i<nodes;i++){
        printf("Enter data for Node %d:",i+1);
        scanf("%d",&node->info);
        if(i==nodes-1)
            node->next = NULL;
        else{
            node->next = (struct NODE*) malloc(sizeof(struct NODE));
            node = node->next;
        }
    }
}
void display(struct NODE *node,int nodes){
    int i=1;
    printf("Details of current Linked List is:\n");
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