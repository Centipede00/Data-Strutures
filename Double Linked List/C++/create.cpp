#include<bits/stdc++.h>
using namespace std;
struct Node {
    int info;
    struct Node *prev;
    struct Node *next;
};
void create(struct Node *node){
    int j=1;
    int value;
    char ch;
    cout<<"Enter data for node "<<j<<":";
    cin>>node->info;
    node->next = NULL;
    j++;

    do{
        cout<<"How many node do you want to enter?:";
        cin>>value;

        if(value==0)
        break;

        for (int i = 0; i < value; i++){
            node->next = (struct Node*) malloc(1 * sizeof(struct Node));
            node->next->prev = node;
            if(node->next == NULL)
                cout<<"Error\n";
            node = node->next;
            cout<<"Enter data for node "<<j<<":";
            cin>>node->info;
            node->next = NULL;
            j++;
        }

        cout<<"Do you want to enter for more nodes?\n";
        cout<<"Enter Y for yes , any other key to exit:";
        fflush(stdin);
        cin>>ch;
        
    } while (ch == 'y' || ch =='Y');
}
void display(struct Node *node){
    int i=1;
    cout<<"\n printing from Starting of the Double Linked List:\n";
    while(node->next!=NULL){
        cout<<"Data at node "<<i<<" is "<<node->info<<" \n";
        i++;
        node = node->next;
    }
    cout<<"Data at node "<<i<<" is "<<node->info<<" \n";

    cout<<"\n printing from Last of the Double Linked List:\n";
    while(node->prev!=NULL){
        cout<<"Data at node "<<i<<" is "<<node->info<<" \n";
        i--;
        node = node->prev;
    }
    cout<<"Data at node "<<i<<" is "<<node->info<<" \n";
}
int main(){
    Node *start;

    start = (struct Node*) malloc(1*sizeof(struct Node));
    start->prev = NULL;
    create(start);
    display(start);

    return 0;
}