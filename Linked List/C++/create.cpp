#include<bits/stdc++.h>
using namespace std;
struct LINKEDLIST {
    int info;
    struct LINKEDLIST *next;
};
void create(struct LINKEDLIST *node){
    int j=1;
    int value;
    char ch;
    cout<<"Enter data for node "<<j<<":"<<endl;
    cin>>node->info;
    node->next = NULL;
    j++;

    do{
        cout<<"How many node do you want to enter?:";
        cin>>value;

        if(value==0)
        break;

        for (int i = 0; i < value; i++){
            node->next = (struct LINKEDLIST*) malloc(1 * sizeof(struct LINKEDLIST));
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
void display(struct LINKEDLIST *node){
    int i=1;
    cout<<"\n";
    while(node->next!=NULL){
        cout<<"Data at node "<<i<<" is "<<node->info<<" \n";
        i++;
        node = node->next;
    }
    cout<<"Data at node "<<i<<" is "<<node->info<<" \n";
}
int main(){
    LINKEDLIST *start;

    start = (struct LINKEDLIST*) malloc(1*sizeof(struct LINKEDLIST));

    create(start);
    display(start);

    return 0;
}