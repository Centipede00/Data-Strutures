#include<stdio.h>
#include<stdlib.h>
struct Node{
    char data;
    struct Node *next;
};
typedef struct{
    struct Node *top;
    int size;
}Stack;
Stack s;
void push(char data){
    struct Node *n;
    n = (struct Node*) malloc(sizeof(struct Node));
    if(n == NULL){
        printf("Stack Overflow\n%d data cannot be inserted inside Stack\n",data);
    }
    else{
        n->data = data;
        if(s.top==NULL){
            n->next = NULL;
            s.top = n;
        }
        else{
            n->next = s.top;
            s.top = n;
        }
    }
}

void pop(){
    struct Node *n;
    if(s.top == NULL){
        printf("Stack Overflow\n");
        printf("No data is present inside Stack\n");
        return;
    }
    else {
        n = s.top;
        s.top = s.top->next;
        free(n);
    }
}

int isBalanced(char *arr){
    for (int i = 0; arr[i]!='\0'; i++){
        if(arr[i] == '(')
            push(arr[i]);
        else if(arr[i] == ')'){
            if(s.top==NULL){
                return 0;
            }
            pop(&s);
        }
    }
    if(s.top == NULL)
        return 1;
    else
        return 0;
}

int main(){
    char *arr = "((a+b)*(c-d))";
    int result = isBalanced(arr);
    if(result == 1)
        printf("In the Given Expression,All Parenthesis is Balanced");
    else
        printf("In the Given Expression,All Parenthesis are not Balanced");

    return 0;
}