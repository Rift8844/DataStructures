#include <iostream>
#include <bits/stdc++.h>
using namespace std;
class Node
{
public :

    int data;
    Node* next;

};

void print_Linked_list(Node* n)
{
    while(n!=NULL)
    {
        cout<<n->data<<" ";
        n=n->next;
    }

}
int main()
{
    Node* head=NULL;
    Node* first=NULL;
    Node* second=NULL;

    head=new Node();
    first=new Node();
    second=new Node();

    /* three new nodes have been created in the memory which has been assigned as null . Now we can assign the data using pointers*/
    head->data=1; //Assigning data to node 1
    head->next=first;//Linking head to next node using pointer next

    first->data=2;
    first->next=second;

    second->data=3;
    second->next=NULL;
    print_Linked_list(head);
    return 0;
}
