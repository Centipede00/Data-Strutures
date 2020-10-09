#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

char pop(){
    struct Node *n;
    char data;
    if(s.top == NULL){
        printf("Stack Overflow\n");
        printf("No data is present inside Stack\n");
    }
    else {
        n = s.top;
        data = n->data;
        s.top = s.top->next;
        free(n);
    }
    return data;
}

int isBalanced(char *arr){
    for (int i = 0; arr[i]!='\0'; i++){
        if(arr[i] == '(')
            push(arr[i]);
        else if(arr[i] == ')'){
            if(s.top==NULL){
                return 0;
            }
            pop();
        }
    }
    if(s.top == NULL)
        return 1;
    else
        return 0;
}

int isOperand(char ch){
    if(ch == '+'||ch == '-'||ch == '*'||ch == '/'||ch == '('||ch == ')')
        return 1;
    else
        return 0;
}

int precedence(char ch){
    if(ch == '+' || ch =='-')
        return 1;
    else if(ch == '*' || ch =='/')
        return 2;
    else if(ch == '^')
        return 3;
    /* else if(ch == '('||ch == ')')
        return 4; */
    else
        return -1;
}

void convert(char *infix,char *postfix){
    int i,j=0;
    printf("debugging-87\n");
    while(infix[i]!='\0'){
        printf("infix[i] = %c\n",infix[i]);
        printf("debugging-88\n");
        if(isOperand(infix[i])){
            if(infix[i]=='('){
                push(infix[i]);
                i++;
            }
            else if(precedence(infix[i])>precedence(s.top->data)){
                push(infix[i]);
                i++;
            }
            else{
                postfix[j] = pop();
                j++;
                i++;
            }
        }
        else{
            postfix[j] = infix[i];
            j++;
            i++;
        }
    }
    printf("debugging-109\n");
    while (s.top!=NULL){
        postfix[j] = pop();
        j++;
    }
    postfix[j-1] = '\0';
    printf("debugging-115\n");
}

int main(){
    char *infix = "((a+b)*(c-d))";
    int result = isBalanced(infix);
    if(result == 1){
        push('#');
        int length = strlen(infix);
        char *postfix = (char *) malloc((length+2)*sizeof(char));
        convert(infix,postfix);
        printf("%s \n",postfix);
    }
    else
        printf("In the Given Expression,All Parenthesis are not Balanced\n");

    return 0;
}