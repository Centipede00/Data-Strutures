#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
        int rear;
        int front;
        int size;
        int *arr;
    public:
        Queue(int size){
            this->size = size;
            front = 0;
            rear = 0;
            arr = new int[size];
        }
        void enqueue(int data);
        int dequeue();
        void display();
        ~Queue(){
            delete arr;
        }
};
void Queue::enqueue(int data){
    if((rear+1)%size==front){
        cout<<"Queue is full,No data can be inserted.\n";
        return;
    }
    rear = (rear+1)%size;
    arr[rear] = data;
}
int Queue::dequeue(){
    int x =-1;
    if(front == rear){
        cout<<"No elements is there inside Queue,So no data can be deleted.\n";
        return x;
    }
    front = (front+1)%size;
    x = arr[front];
    return x;
}
void Queue::display(){
    if(front == rear){
        cout<<"No elements is there inside Queue.\n";
        return;
    }
    int i = front+1;
    do{
        cout<<arr[i]<<" ";
        i = (i+1)%size;
    } while (i!=(rear+1)%size);
    cout<<"\n";
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
}