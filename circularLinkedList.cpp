#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;

// Insert at End
void insertEnd(int value)
{
    Node *newNode = new Node;
    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while(temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
}

// Insert at Beginning
void insertBeginning(int value)
{
    Node *newNode = new Node;
    newNode->data = value;

    if(head == NULL)
    {
        head = newNode;
        newNode->next = head;
        return;
    }

    Node *temp = head;

    while(temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    head = newNode;
}

// Delete First Node
void deleteBeginning()
{
    if(head == NULL)
        return;

    if(head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;
    Node *last = head;

    while(last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;

    delete temp;
}

// Delete Last Node
void deleteEnd()
{
    if(head == NULL)
        return;

    if(head->next == head)
    {
        delete head;
        head = NULL;
        return;
    }

    Node *temp = head;

    while(temp->next->next != head)
        temp = temp->next;

    Node *last = temp->next;
    temp->next = head;
    delete last;
}

// Search
void search(int value)
{
    if(head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        if(temp->data == value)
        {
            cout << "Found\n";
            return;
        }

        temp = temp->next;

    }while(temp != head);

    cout << "Not Found\n";
}

// Display
void display()
{
    if(head == NULL)
    {
        cout << "List Empty\n";
        return;
    }

    Node *temp = head;

    do
    {
        cout << temp->data << " ";
        temp = temp->next;

    }while(temp != head);

    cout << endl;
}

int main()
{
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);

    insertBeginning(5);

    display();

    deleteBeginning();
    display();

    deleteEnd();
    display();

    search(20);

    return 0;
}
