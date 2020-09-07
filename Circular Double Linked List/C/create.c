#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
struct Node *last;
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
void display(struct Node *node){
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
}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    start = node;
    node->prev = NULL;
    create(node);
    display(start);

    return 0;
}