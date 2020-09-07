#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
void create(struct Node *node){
    int j=1;
    int value;
    char ch;
    printf("Enter data for node %d:",j);
    scanf("%d",&node->info);
    node->next = NULL;
    j++;

    do{
        printf("How many node do you want to enter?:");
        scanf("%d",&value);

        if(value==0)
        break;

        for (int i = 0; i < value; i++){
            node->next = (struct Node*) malloc(1 * sizeof(struct Node));
            node->next->prev = node;
            if(node->next == NULL)
                printf("Error\n");
            node = node->next;
            printf("Enter data for node %d:",j);
            scanf("%d",&node->info);
            node->next = NULL;
            j++;
        }

        printf("Do you want to enter for more nodes?");
        printf("Enter Y for yes , any other key to exit:");
        fflush(stdin);
        scanf("%c",&ch);
        
    } while (ch == 'y' || ch =='Y');
    
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

    printf("\n");
    printf("printing from Last of double linked list: \n");
    while(node->prev!=NULL){
        printf("Data at node %d is %d \n",i,node->info);
        i--;
        node = node->prev;
    }
    printf("Data at node %d is %d \n",i,node->info);
}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    node->prev = NULL;
    start = node;
    create(node);
    display(start);

    return 0;
}