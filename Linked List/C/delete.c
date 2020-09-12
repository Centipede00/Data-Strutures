#include<stdio.h>
#include<stdlib.h>
struct NODE{
    int info;
    struct NODE *next;
};
void delete(struct NODE *,int);
void searchDelete(struct NODE *,int);
void create(struct NODE *,int);
void display(struct NODE *);
struct NODE *head;
void searchDelete(struct NODE *node,int data){
    int found =0,k=1;
    while(node!=NULL){
        if(node->info==data){
            delete(head,k);
            found=1;
            break;
        }
        node = node->next;
        k++;
    }
    if(found == 0)
        printf("%d is not present inside Linked List\n",data);
}
void delete(struct NODE *node,int position){
    struct NODE *p,*q;
    p = head;
    int k=1;
    if(position==1){
        node = p->next;
        p->next = NULL;
        head = node;
        free(p);
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
        }
        else{
            q->next = p->next;
            free(p);
        }
    }
}
void create(struct NODE *node,int nodes){
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
    printf("\nDetails of current Linked List is:\n");
    printf("Data present inside Nodes:\n");
    while(node!=NULL){
        printf("Node %d: %d\n",i,node->info);
        node = node->next;
        i++;
    }
    printf("Number of nodes present:%d\n",i-1);
}
int main(){
    struct NODE *node;
    int nodes,option,position,data;
    printf("How many nodes do you want to create?:");
    scanf("%d",&nodes);
    node = (struct NODE*) malloc(sizeof(struct NODE));
    node->next = NULL;
    head = node;
    create(node,nodes);
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
            delete(node,1);
        }
        else if(option ==2){
            delete(node,nodes+1);
        }
        else if(option==3){
            printf("Enter the position to delete:");
            scanf("%d",&position);
            delete(node,position);
        }
        else if(option==4){
            printf("Enter the data of node,which will be deleted:");
            scanf("%d",&data);
            searchDelete(node,data);
        }
        else if(option == 5){
            break;
        }
        else{
            printf("Invalid Option\n");
        }
        display(head);
        system("pause");
    }
    return 0;
}