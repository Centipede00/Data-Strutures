#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
void reverse(struct Node *node){
    struct Node *current,*previous,*ptr;
    current = node;
    previous = current->next;
    current->next = NULL;
    while(previous->next!=NULL){
        current->prev = previous;
        ptr = previous->next;
        previous->next = current;
        current = previous;
        previous = ptr;
    }
    current->prev = previous;
    previous->prev = NULL;
    previous->next = current;
    start = previous;
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
    printf("Nodes present:%d\n",i);
    printf("\n");
    int j=1;
    printf("printing from Last of double linked list: \n");
    while(node->prev!=NULL){
        printf("Data at node %d is %d \n",i,node->info);
        i--;
        j++;
        node = node->prev;
    }
    printf("Data at node %d is %d \n",i,node->info);
    printf("Nodes present:%d\n",j);
}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    node->prev = NULL;
    create(node);
    start = node;
    printf("Double Linked List before Reversing:\n");
    display(start);
    reverse(node);
    printf("Double Linked List After Reversing:\n");
    display(start);
    return 0;
}