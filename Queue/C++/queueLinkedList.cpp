#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node *next;
};
class Queue{
    private:
        int size;
        int maxSize;
        Node *front;
        Node *rear;
    public:
        Queue(int size);
        void enqueue(int data);
        int dequeue();
        void display();
        ~Queue();
};
Queue::Queue(int size){
    this->size = size;
    front = NULL;
    rear = NULL;
    maxSize=0;
}
void Queue::enqueue(int data){
    Node *temp = new Node;
    if(temp == NULL || maxSize>size-1){
        printf("Queue is full,Overflow\n");
        return;
    }
    temp->data = data;
    temp->next = NULL;
    if(front==NULL){
        front = temp;
        rear = temp;
    }
    else{
        rear->next = temp;
        rear = temp;
    }
    maxSize++;
}
int Queue::dequeue(){
    int x=-1;
    if(front==NULL){
        printf("Queue is empty,Underflow\n");
        return x;
    }
    Node *temp = front;
    front = front->next;
    x = temp->data;
    free(temp);
    return x;
}
void Queue::display(){
    if(front==NULL){
        printf("Queue is empty.\n");
        return;
    }
    Node *temp = front;
    while(temp!=rear){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<temp->data<<"\n";
}
Queue::~Queue(){
    Node *temp = front;
    while(front){
        front = front->next;
        delete temp;
        temp = front;
    }
}
int main(){
    int size;
    cout<<"Enter the size of queue:";
    cin>>size;
    Queue q(size);
    int option,data;
    while(1>0){
        cout<<"\tOptions Available:\n";
        cout<<"1.Insert an element into queue.\n";
        cout<<"2.delete an element from queue.\n";
        cout<<"3.display the queue.\n";
        cout<<"4.Exit/Quit.\n";
        cout<<"Enter any options between 1-4:";
        cin>>option;
        if(option==1){
            cout<<"Enter the data:";
            cin>>data;
            q.enqueue(data);
            system("pause");
        }
        else if(option==2){
            data = q.dequeue();
            if(data!=-1)
                cout<<data<<" has be deleted from queue.\n";
            system("pause");
        }
        else if(option==3){
            q.display();
            system("pause");
        }
        else if(option==4){
            break;
        }
        else{
            cout<<"Invalid option\n";
            cout<<"Please try again\n";
        }
    }
    return 0;
}