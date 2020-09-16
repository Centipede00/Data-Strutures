#include<stdio.h>
#include<stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
typedef struct{
    struct Node *top;
    int pos;
    int size;
}Stack;
void push(Stack *s,int data){
    struct Node *n;
    n = (struct Node*) malloc(sizeof(struct Node));
    if(s->pos == s->size-1 || n == NULL){
        printf("Stack Overflow\n%d data cannot be inserted inside Stack\n",data);
    }
    else{
        n->data = data;
        s->pos++;
        if(s->top==NULL){
            n->next = NULL;
            s->top = n;
        }
        else{
            n->next = s->top;
            s->top = n;
        } 
    }
}
int pop(Stack *s){
    struct Node *n;
    int data = -1;      //initializing data with -1,if condition satisfies it will return -1,else it will return last element of stack
    if(s->top == NULL){
        printf("Stack Overflow\n");
        printf("No data is present inside Stack\n");
    }
    else {
        n = s->top;
        data = n->data;
        s->top = s->top->next;
        s->pos--;
        free(n);
    }
    return data;
}
int peek(Stack s,int pos){
    if(s.top == NULL){

    }
    else{
        struct Node *n = s.top;
        for(int i=0;n!=NULL && i<pos-1;i++)
            n = n->next;
        
        if(n!=NULL)
            return n->data;
        else{
            printf("Given position is greater than size of Stack\n");
            return -1;
        }
    }
}
int stackTop(Stack s){
    if(s.top == NULL){
        printf("Stack Overflow\n");
        printf("No data is present inside Stack\n");
        return -1;
    }
    else    
        return s.top->data;
}
void isEmpty(Stack s){
    if(s.top==NULL){
        printf("Stack is Empty.\n");
    }
    else 
        printf("Stack is not Empty,Data is present inside Stack\n");
}
void isFull(Stack s){
    if(s.pos == s.size-1){
        printf("Stack is Full.\n");
    }
    else 
        printf("Stack is not Full,More element can be pushed inside Stack\n");
}
void display(Stack s){
    struct Node *n;
    n = s.top;
    if(s.top == NULL){
        printf("No data is present inside the Stack\n");
    }
    else {
        printf("Data inside Stack:\n");
        while (n!=NULL){
            printf("%d\n",n->data);
            n = n->next;
        }
        printf("\nStack Size:%d\n",s.size);
        printf("Stack Top:%d\n",s.top->data);
    }
}
int main(){
    Stack s;
    s.top = NULL;
    s.pos = -1;
    printf("Enter the Details for Stack:\n");
    printf("Enter Size:");
    scanf("%d",&s.size);
    int option,data,pos;
    while (1>0){
        printf("\n\tOptions Available:\n");
        printf("1.Push an Element inside Stack\n");
        printf("2.Pop an element outside Stack\n");
        printf("3.peek or get an Element of Stack\n");
        printf("4.Get Stack Top,its element\n");
        printf("5.Check weather stack is empty or not\n");
        printf("6.Check weather stack is full or not\n");
        printf("7.Display the details of Stack\n");
        printf("8.Quit\n");
        printf("Enter Any options between 1-8:");
        scanf("%d",&option);

        if (option==1){
            printf("\nEnter the Data:");
            scanf("%d",&data);
            push(&s,data);
            system("pause");
        }
        else if (option==2){
            data = pop(&s);
            if(data!=-1)
                printf("%d has been poped out of Stack\n",data);
            system("pause");
        }
        else if (option==3){
            printf("\nEnter the Position:");
            scanf("%d",&pos);
            data = peek(s,pos);
            if(data!=-1)
                printf("%d is present in %d position\n",data,pos);
            system("pause");
        }
        else if (option==4){
            data = stackTop(s);
            if(data!=-1)
                printf("%d is present at stack Top\n",data);
            system("pause");
        }
        else if (option==5){
            isEmpty(s);
            system("pause");
        }
        else if (option==6){
            isFull(s);
            system("pause");
        }
        else if (option==7){
            printf("Details of Stack:\n");
            display(s);
            system("pause");
        }
        else if (option==8){
            break;
        }
        else{
            printf("Invalid option\n");
        }        
    }
    return 0;
}