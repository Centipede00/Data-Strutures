#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
struct Node *last;
void searchDelete(struct Node *node,int data){
    int found,k=1;
    while(node->next!=NULL){
        if(node->info==data){
            delete(node,k);
            found = 1;
            break;
        }
        found = 0;
        node = node->next;
        k++;
    }
    if(node->info==data){
            delete(node,k);
            found = 1;
    }
    if(found == 0 ){
        printf("%d is not present inside Double Linked List\n",data);
    }
}
void delete(struct Node *node,int position){
    struct Node *p,*q;
    p = start;
    int found,k=1;
    if(position==1){
        node = node->next;
        last->next = node;
        node->prev = last;
        start=node;
        free(p);
        found =1;
    }
    else{
        while((p->next!=start) && (k<position)){
            k++;
            q=p;
            p = p->next;
        }
        if(p->next==start){
            last = q;
            q->next = start;
            start->prev = last;
            free(p);
            found = 1;
        }
        else{
            q->next = p->next;
            p->next->prev = q;
            free(p);
            found = 1;
        }
    }
    if(found!=1){
        printf("%d position exceeds the size of Double Linked List size\n",position);
    }
    else
    k = display(start);
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
        last = node;
        node->next = start;
        node = node->next;
        node->prev = last;
}
int display(struct Node *node){
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

    return j;
}
int main(){

    struct Node *node;
    node = (struct Node*) malloc(1 * sizeof(struct Node));
    start = node;
    node->prev = NULL;
    create(node);
    int nodes = display(start);
    int option,position,data;
    printf("\n\tOperations Available:\n");
        printf("1.deletion at the beginning of the List\n");
        printf("2.deletion at the End of the List\n");
        printf("3.deletion at a particular position\n");
        printf("4.deletion of a given node\n");
        printf("Enter any option(1-4):");
        scanf("%d",&option);
    switch (option){
        case 1: delete(node,1);
            break;

        case 2:
            delete(node,nodes+1);
            break;
        
        case 3:printf("Enter the position of node,which will be deleted:");
                scanf("%d",&position);
                delete(node,position);

           break;
        
        case 4:printf("Enter the data of node,which will be deleted:");
                scanf("%d",&data);
                searchDelete(node,data);
            break;
        default:printf("Invalid option\n");
            break;
        }
    return 0;
}