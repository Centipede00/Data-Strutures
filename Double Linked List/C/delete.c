#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;

void searchDelete(struct Node *,int);
void delete(struct Node *,int);
void create(struct Node *,int);
void display(struct Node *);


void searchDelete(struct Node *node,int data){
    int found =0 ,k=1;
    while(node!=NULL){
        printf("%d-info,%d-data\n",node->info,data);
        if(node->info==data){
            delete(node,k);
            found = 1;
            break;
        }
        node = node->next;
        k++;
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
        node->prev = NULL;
        start=node;
        free(p);
        found =1;
    }
    else{
        while((p->next!=NULL) && (k<position)){
            k++;
            q=p;
            p = p->next;
        }
        if(p->next==NULL){
            q->next = NULL;
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
}

void create(struct Node *node,int nodes){
    int j=1;
    for (int i = 0; i < nodes; i++){
        printf("Enter data for node %d:",j);
        scanf("%d",&node->info);
        node->next = NULL;
        j++;
        if(i+1!=nodes){
            node->next = (struct Node*) malloc(1 * sizeof(struct Node));
            if(node->next == NULL){
                printf("Error\n");
                return;
            }
            node->next->prev = node;
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
    start = node;

    int nodes;
    printf("How many node do you want to enter?:");
    scanf("%d",&nodes);
    create(node,nodes);

    int option,position,data;
    while (option!=5){
        printf("\n\tOperations Available:\n");
        printf("1.Deletion at the beginning of the List\n");
        printf("2.Deletion at the End of the List\n");
        printf("3.Deletion at a particular position\n");
        printf("4.Deletion after a given node\n");
        printf("5.Quit\n");
        printf("Enter any option(1-4):");
        scanf("%d",&option);
        if(option == 1){
            delete(start,1);
        }
        else if(option ==2){
            delete(start,nodes+1);
        }
        else if(option==3){
            printf("Enter the position to delete:");
            scanf("%d",&position);
            if(position<=nodes){
                delete(start,position);
            }
            else{
                printf("Invalid Position\n");
            }
        }
        else if(option==4){
            printf("Enter the data of node,which will be deleted:");
            scanf("%d",&data);
            searchDelete(start,data);
        }
        else if(option == 5){
            break;
        }
        else{
            printf("Invalid Option\n");
        }
        display(start);
        system("pause");
    }
    return 0;
}