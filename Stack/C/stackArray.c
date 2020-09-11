#include<stdio.h>
#include<stdlib.h>
struct Stack{
    int size;
    int top;
    int *arr;
};
struct Stack s;
void push(struct Stack *s,int data){
    if(s->top == s->size-1){
        printf("Stack Overflow\n%d data cannot be inserted inside Stack\n",data);
    }
    else{
        s->top++;
        s->arr[s->top] = data;
    }
}
int pop(struct Stack *s){
    int data = -1;      //initializing data with -1,if condition satisfies it will return -1,else it will return last element of stack
    if(s->top == -1){
        printf("Stack Overflow\n");
        printf("No data is present inside Stack\n");
    }
    else {
        data = s->arr[s->top];
        s->top--;
    }
    return data;
}
int peek(struct Stack s,int position){
    int data = -1;      //initializing data with -1,if condition satisfies it will return -1,else it will return the disired element
    if(s.top-position+1 < 0){
        printf("Invalid Position\n");
    }
    else {
        data = s.arr[s.top-position+1];
    }
    return data;    
}
int stackTop(struct Stack s){
    if(s.top == -1){
        printf("Stack Overflow\n");
        printf("No data is present inside Stack\n");
        return -1;
    }
    else    
        return s.arr[s.top];
}
void isEmpty(struct Stack s){
    if(s.top==-1){
        printf("Stack is Empty.\n");
    }
    else 
        printf("Stack is not Empty,Data is present inside Stack\n");
}
void isFull(struct Stack s){
    if(s.top == s.size-1){
        printf("Stack is Full.\n");
    }
    else 
        printf("Stack is not Full,More element can be pushed inside Stack\n");
}
void display(struct Stack s){
    if(s.top == -1){
        printf("No data is present inside the Stack\n");
    }
    else {
        printf("Data inside Stack:\n");
        for (int i = s.top; i >=0 ; i--){
            printf("%d\n",s.arr[i]);
        }
        printf("Stack Size:%d\n",s.size);
        printf("Stack Top:%d\n",s.top+1);
    }
}
int main(){
    int option,data,pos;
    printf("Enter the Details for Stack:\n");
    printf("Enter Size:");
    scanf("%d",&s.size);
    s.arr = (int *) malloc(s.size * sizeof(int));
    s.top = -1;
    while (1>0){
        printf("\n\nOptions Available:\n");
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