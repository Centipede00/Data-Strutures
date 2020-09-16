#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};
class Stack{
    private:
        Node *top;
        int pos;
        int size;
    public:
        Stack(int size);
        void push(int data);
        int pop();
        int peek(int position);
        void isEmpty();
        void isFull();
        int stackTop();
        void display();
        ~Stack();
};

Stack::Stack(int size){
    top = NULL;
    this->size = size;
    pos = -1;
}

void Stack::push(int data){
    Node *n = new Node;
    if(n==NULL || pos == size-1){
        cout<<"Stack Overflow!!"<<endl;
        cout<<data<<" cannot be pushed inside the stack\n";
    }
    else{
        n->data = data;
        pos++;
        if(top == NULL){
            n->next = NULL;
            top = n;
        }
        else{
            n->next = top;
            top = n;
        }
    }
}

int Stack::pop(){
    Node *n = new Node;
    int data = -1;
    if(top == NULL){
        cout<<"Stack is Empty\n";
        return data;
    }
    else{
        n = top;
        data = n->data;
        top = top->next;
        pos--;
        delete n;
        return data;
    }
}

int Stack::peek(int position){
    if(top == NULL){
        cout<<"Stack is Empty,So Element not found\n";
        return -1;
    }
    else{
        Node *n = top;
        for(int i=0;n!=NULL && i<position-1;i++)
            n = n->next;
        
        if(n!=NULL)
            return n->data;
        else{
            cout<<"Given position is greater than size of Stack\n";
            return -1;
        }
    }
}

void Stack::isEmpty(){
    if(top==NULL)
        cout<<"Stack is Empty\n";
    else
        cout<<"Stack is not Empty,data is present inside it.\n";
}

void Stack::isFull(){
    if(pos == size-1)
        cout<<"Stack is Full\n";
    else
        cout<<"Stack is not Full,more data can be pushed.\n";
}

int Stack::stackTop(){
    if(top == NULL){
        cout<<"Stack is Empty\n";
        return -1;
    }
    else{
        return top->data;
    }
}

void Stack::display(){
    Node *n = top;
    if(top == NULL)
        cout<<"Stack is Empty\n";
    else{
        cout<<"Stack Details:\n";
        cout<<"Stack Size:"<<size<<"\n";
        cout<<"Data inside stack:\n";
        while (n!=NULL){
            cout<<n->data<<endl;
            n = n->next;
        }
    }
}

Stack::~Stack(){
    Node *n = top;
    while(top){
        top = top->next;
        delete n;
        n = top;
    }
}

int main(){
    int size,option = 0,data,pos;
    cout<<"Enter the size of the Stack:";
    cin>>size;
    Stack s(size);
    while(option!=8){
        cout<<"\n\tOptions available:\n";
        cout<<"1.Push an Element inside Stack\n";
        cout<<"2.Pop an element outside Stack\n";
        cout<<"3.Peek an element,or visit an element\n";
        cout<<"4.Get Stack Top,its element\n";
        cout<<"5.Check weather stack is empty or not\n";
        cout<<"6.Check weather stack is full or not\n";
        cout<<"7.Display the details of Stack\n";
        cout<<"8.Quit\n";
        cout<<"Enter Any options between 1-8:";
        cin>>option;

        if(option == 1){
            cout<<"Enter the Data:";
            cin>>data;
            s.push(data);
            system("pause");
        }
        else if(option == 2){
            data = s.pop();
            if(data!=-1)
                cout<<data<<" has Been poped out of Stack\n";
                system("pause");
        }
        else if(option == 3){
            cout<<"enter the position:";
            cin>>pos;
            data = s.peek(pos);
            if(data!=-1)
                cout<<data<<" is present at "<<pos<<" position\n";
            system("pause");
        }
        else if(option == 4){
            data = s.stackTop();
            if(data !=-1)
                cout<<data<<" is present at Top\n";
            system("pause");
        }
        else if(option == 5){
            s.isEmpty();
            system("pause");
        }
        else if(option == 6){
            s.isFull();
            system("pause");
        }
        else if(option == 7){
            s.display();
            system("pause");
        }
        else if(option == 8){
            s.~Stack();
            break;
        }
        else{
            cout<<"Invalid Option\nTry Again\n";
        }
    }
    return 0;
}