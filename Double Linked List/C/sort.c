#include<stdio.h>
#include<stdlib.h>
struct Node{
    int info;
    struct Node *prev;
    struct Node *next;
};
struct Node *start;
void swap(struct Node *node1,struct Node *node2){
    int temp = node1->info;
    node1->info = node2->info;
    node2->info = temp;
}
void sort(struct Node *node){
    struct Node *p;
    struct Node *q = NULL;
    int swapped;
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
    start = node;
    node->prev = NULL;
    create(node);
    printf("\n\nDouble Linked List Before Sorting:\n");
    display(start);

    sort(start);
    printf("\n\nDouble Linked List After Sorting:\n");
    display(start);
    return 0;
}