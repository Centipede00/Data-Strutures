#include<stdio.h>
#include<stdlib.h>
struct LinkedList{
    int info;
    struct LinkedList *next;
};
void create(struct LinkedList *node){
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
            node->next = (struct LinkedList*) malloc(1 * sizeof(struct LinkedList));
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
void display(struct LinkedList *node){
    int i=1;
    printf("\n");
    while(node->next!=NULL){
        printf("Data at node %d is %d \n",i,node->info);
        i++;
        node = node->next;
    }
    printf("Data at node %d is %d \n",i,node->info);
}
int main(){

    struct LinkedList *start;
    start = (struct LinkedList*) malloc(1 * sizeof(struct LinkedList));
    create(start);
    display(start);

    return 0;
}