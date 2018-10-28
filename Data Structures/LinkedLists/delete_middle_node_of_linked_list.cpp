#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};
struct Node *head=NULL;
/* Function to Insert a node in beginning */
void Insert(int dataToBeInserted)
{
    struct Node* curr = new Node;
    curr->data = dataToBeInserted;
    curr->next = NULL;
    if(head == NULL)
            head=curr; //If this is first node make this as head of list

    else
        {
            curr->next = head; //else make the curr (new) node's next point to head and make this new node a the head
            head=curr;
        }


}

//display linked list
void display()
{
    struct Node *temp= head;
    while(temp!=NULL)
        {
            if(temp->next!=NULL)
            cout<<temp->data<<"->";
            else
            cout<<temp->data;

            temp=temp->next; //move to next node
        }

    cout<<endl;
}

// function to get the length of linked list
int getLength()
{
    int length = 0;  // Initialize length
    struct Node* current = head;  // Initialize current
    while (current != NULL)
    {
        length++;
        current = current->next;
    }
    return length;
}

// function to delete the middle node
void del( int position)
{
   // If linked list is empty
   if (head == NULL)
      return;

   // Store head node
   struct Node* temp = head;
   struct Node* head_ref=head;// create a new head reference

    // If head needs to be removed
    if (position == 0)
    {
        head_ref = temp->next;   // Change head
        cout<<"Middle element "<<temp->data<<" is deleted\n";
        free(temp);               // free old head
        return;
    }

    // Find previous node of the node to be deleted
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;

    // If position is more than number of ndoes
    if (temp == NULL || temp->next == NULL)
         return;

    // Node temp->next is the node to be deleted
    // Store pointer to the next of node to be deleted
    struct Node *next = temp->next->next;
    cout<<"Middle element "<<temp->next->data<<" is deleted\n";
    // Unlink the node from linked list
    free(temp->next);  // Free memory

    temp->next = next;  // remove the deleted node
}
//Main function
int main()
{
    //Initial list has no elements
    // Insert elements to the Linked List
    Insert(6);
    Insert(2);
    Insert(4);
    Insert(7);
    Insert(9);
    Insert(8);
    Insert(1);
    Insert(5);
    Insert(3);

    cout<<"Input linked list is: ";
    display();
    del(getLength()/2);
    cout<<"Linked list after deletion is: ";
    display();
    return 0;
}
