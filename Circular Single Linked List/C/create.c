#include<stdio.h>
#include<stdlib.h>
struct Node{
    int node_key;
    int info;
    struct Node *next;
};
struct Node *head;
void create(struct Node *node){
    int j=1;
    int value;
    char ch;
    printf("Enter data for node %d:",j);
    scanf("%d",&node->info);
    node->node_key = j;
    node->next = NULL;
    j++;

    do{
        printf("How many node do you want to enter?:");
        scanf("%d",&value);

        if(value==0)
        break;

        for (int i = 0; i < value; i++){
            node->next = (struct Node*) malloc(1 * sizeof(struct Node));
            if(node->next == NULL)
                printf("Error\n");
            node = node->next;
            printf("Enter data for node %d:",j);
            scanf("%d",&node->info);
            node->node_key = j;
            node->next = NULL;
            j++;
        }
        node->next = head;
        printf("Do you want to enter for more nodes?");
        printf("Enter Y for yes , any other key to exit:");
        fflush(stdin);
        scanf("%c",&ch);
        
    } while (ch == 'y' || ch =='Y');
    
}
void display(struct Node *node){
    int i=1;
    printf("\n");
    printf("Data of the Circular single Linked list:\n");
    while(node->next!=head){
        printf("Data at node %d is %d \n",node->node_key,node->info);
        i++;
        node = node->next;
    }
    printf("Data at node %d is %d \n",node->node_key,node->info);
}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    head = node;
    create(node);
    display(head);

    return 0;
}