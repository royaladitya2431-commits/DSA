#include <iostream>
using namespace std;

//----------------------------
// Step 1 : Define Node
//----------------------------
struct Node
{
    int data;
    Node *next;
};

//----------------------------
// Step 2 : Create LinkedList Class
//----------------------------
class LinkedList
{
private:
    Node *head;

public:

    // Constructor
    LinkedList()
    {
        head = NULL;
    }

    //----------------------------
    // Create Initial List
    //----------------------------
    void createList()
    {
        int n, value;

        cout << "\nEnter number of nodes : ";
        cin >> n;

        if(n <= 0)
        {
            cout << "Invalid number of nodes.";
            return;
        }

        for(int i = 1; i <= n; i++)
        {
            cout << "Enter value " << i << " : ";
            cin >> value;

            insertEnd(value);
        }

        cout << "\nLinked List Created Successfully.\n";
    }

    //----------------------------
    // Insert Node at Beginning
    //----------------------------
    void insertBeginning(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = head;

        head = newNode;
    }

    //----------------------------
    // Insert Node at End
    //----------------------------
    void insertEnd(int value)
    {
        Node *newNode = new Node;

        newNode->data = value;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    //----------------------------
    // Delete Node by Value
    //----------------------------
    void deleteNode(int value)
    {
        if(head == NULL)
        {
            cout << "\nList is Empty.\n";
            return;
        }

        Node *temp = head;
        Node *previous = NULL;

        if(head->data == value)
        {
            head = head->next;
            delete temp;

            cout << "\nNode Deleted.\n";
            return;
        }

        while(temp != NULL && temp->data != value)
        {
            previous = temp;
            temp = temp->next;
        }

        if(temp == NULL)
        {
            cout << "\nValue Not Found.\n";
            return;
        }

        previous->next = temp->next;
        delete temp;

        cout << "\nNode Deleted Successfully.\n";
    }

    //----------------------------
    // Display Linked List
    //----------------------------
    void display()
    {
        if(head == NULL)
        {
            cout << "\nLinked List is Empty.\n";
            return;
        }

        Node *temp = head;

        cout << "\nLinked List : ";

        while(temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
};

//----------------------------
// Main Function
//----------------------------
int main()
{
    LinkedList list;

    int choice;
    int value;

    do
    {
        cout << "\n==============================";
        cout << "\n LINKED LIST MENU";
        cout << "\n==============================";
        cout << "\n1. Create List";
        cout << "\n2. Insert at Beginning";
        cout << "\n3. Insert at End";
        cout << "\n4. Delete Node";
        cout << "\n5. Display List";
        cout << "\n6. Exit";

        cout << "\nEnter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                list.createList();
                break;

            case 2:
                cout << "\nEnter value to insert : ";
                cin >> value;

                list.insertBeginning(value);

                cout << "\nNode Inserted.";
                break;

            case 3:
                cout << "\nEnter value to insert : ";
                cin >> value;

                list.insertEnd(value);

                cout << "\nNode Inserted.";
                break;

            case 4:
                cout << "\nEnter value to delete : ";
                cin >> value;

                list.deleteNode(value);
                break;

            case 5:
                list.display();
                break;

            case 6:
                cout << "\nProgram Ended.";
                break;

            default:
                cout << "\nInvalid Choice.";
        }

    } while(choice != 6);

    return 0;
}