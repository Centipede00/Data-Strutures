#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
void swap(struct NODE *node1 , struct NODE *node2){
    int temp = node1->info;
    node1->info = node2->info;
    node2->info = temp;
}
void sort(struct NODE *node){
    struct NODE *p;
    struct NODE *q=NULL;
    int swapped = 10;
    do{
        swapped = 0;
        p = node;
        while (p->next!=q){
            if(p->info > p->next->info){
                swap(p,p->next);
                swapped = 1;
            }
            p = p->next;
        }
        q = p;
    } while (swapped);
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
void display(struct NODE *node){
    int i=1;
    printf("Details of current Linked List is:\n");
    printf("Data present inside Nodes:\n");
    while(node){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Number of nodes present:%d\n",i-1);
}
int main(){
    struct NODE *head,*node;
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node);

    printf("\n\nLinked List Before Sorting:\n");
    display(head);

    sort(head);
    printf("\n\nLinked List After Sorting:\n");
    display(head);
    return 0;
}