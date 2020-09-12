#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
struct NODE *head;
void create(struct NODE *);
void display(struct NODE *);
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
void display(struct NODE *node){
    int i=1;
    printf("\n\nDetails of current Linked List is:\n");
    printf("\nData present inside Nodes:\n");
    while(node->next!=NULL){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Node %d: %d\n",i,node->info);
    printf("Number of nodes present:%d\n",i);
}
int main(){
    struct NODE *node;
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node);
    display(head);
    return 0;
}