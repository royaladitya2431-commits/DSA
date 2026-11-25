
#include <iostream>
using namespace std;

class Hashing
{
    int table[10];

public:
    Hashing()
    {
        for(int i = 0; i < 10; i++)
            table[i] = -1;
    }

    // Insert element
    void insert(int key)
    {
        int index = key % 10;

        while(table[index] != -1)
        {
            index = (index + 1) % 10;
        }

        table[index] = key;
        cout << "Element inserted\n";
    }

    // Search element
    void search(int key)
    {
        int index = key % 10;
        int start = index;

        while(table[index] != -1)
        {
            if(table[index] == key)
            {
                cout << "Element found at index "
                     << index << endl;
                return;
            }

            index = (index + 1) % 10;

            if(index == start)
                break;
        }

        cout << "Element not found\n";
    }

    // Display hash table
    void display()
    {
        cout << "\nHash Table:\n";

        for(int i = 0; i < 10; i++)
        {
            cout << i << " --> "
                 << table[i] << endl;
        }
    }
};

int main()
{
    Hashing h;
    int choice, key;

    do
    {
        cout << "\n1. Insert";
        cout << "\n2. Search";
        cout << "\n3. Display";
        cout << "\n4. Exit";

        cout << "\nEnter choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                h.insert(key);
                break;

            case 2:
                cout << "Enter key: ";
                cin >> key;
                h.search(key);
                break;

            case 3:
                h.display();
                break;

            case 4:
                cout << "Exiting...";
                break;

            default:
                cout << "Invalid choice";
        }

    } while(choice != 4);

    return 0;
}
