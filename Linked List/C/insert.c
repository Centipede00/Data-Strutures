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

    struct LinkedList *start,*new;
    start = (struct LinkedList*) malloc(1 * sizeof(struct LinkedList));
    new = (struct LinkedList*) malloc(1 * sizeof(struct LinkedList));
    create(start);
    display(start);

    int option;
    char ch;
    do
    {
        printf("Enter data for new node:");
        scanf("%d",&new->info);
        if(new->next==NULL)
        printf("data of new node is null");
        printf("Operations Available:\n");
        printf("1.Insertion at the beginning of the List\n");
        printf("2.Insertion at the End of the List\n");
        printf("3.Insertion at a particular position\n");
        printf("4.Insertion After a particular node\n");
        printf("Enter any option(1-4):\n");
        scanf("%d",&option);

        switch (option)
        {
        case 1:
            new->next = start;
            start = new;
            printf("Case -1\n");
            break;

        case 2:
            /* do
            {
                start = start->next;
                if(start->next == NULL){
                    start->next = new;
                    new->next = NULL;
                }
            } while (new->next != NULL); */
            while(new->next != NULL){
                if(start->next == NULL){
                    printf("%d->next == NULL\n",start->info);
                    new->next = NULL;
                    start->next = new;
                }
                else{
                    printf("%d->next != NULL\n",start->info);
                    start = start->next;
                }
            }
            
            break;
        
        case 3:
            
            break;

        case 4:
            
            break;

        default:printf("Invalid option\n");
            break;
        }
        display(start);
        printf("Do you want to enter for more nodes?");
        printf("Enter Y for yes , any other key to exit:");
        fflush(stdin);
        scanf("%c",&ch);
    } while (ch == 'y' || ch == 'Y');
    


    return 0;
}