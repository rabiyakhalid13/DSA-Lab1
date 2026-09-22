#include <iostream>
using namespace std;

// a single node in the linked list:
struct Node {
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* toDelete = current;
            current = current->next;
            delete toDelete;
        }
    }

    // 1. insert a new node at the head of the list
    void insertAtHead(int value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " at head.\n";
    }

    // 2. insert a new node at the 3rd position of the list
    void insertAtThird(int value) {
        Node* newNode = new Node(value);

        // 0 or 1 nodes currently in the list thus cannot reach a 3rd position
        if (head == nullptr || head->next == nullptr) {
            cout << "List has fewer than 2 nodes. Inserting at the end instead.\n";
            if (head == nullptr) {
                head = newNode;
            } else {
                head->next = newNode;
            }
            return;
        }

        // traverse to the 2nd node so we can insert right after it
        Node* current = head->next; // 2nd node
        newNode->next = current->next;
        current->next = newNode;
        cout << "Inserted " << value << " at the 3rd position.\n";
    }

    // 3. display the list
    void displayList() const {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL\n";
    }

    // 4. delete the last node
    void deleteLast() {
        if (head == nullptr) {
            cout << "List is empty. Nothing to delete.\n";
            return;
        }

        if (head->next == nullptr) { // only one node
            cout << "Deleting only node (" << head->data << ").\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        cout << "Deleting last node (" << current->next->data << ").\n";
        delete current->next;
        current->next = nullptr;
    }

    // 5. count nodes
    int countNodes() const {
        int count = 0;
        Node* current = head;
        while (current != nullptr) {
            count++;
            current = current->next;
        }
        return count;
    }

    // 6. reverse the list
    void reverseList() {
        Node* prev = nullptr;
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next; // save next
            current->next = prev;           // reverse the link
            prev = current;                 // advance prev
            current = nextNode;             // advance current
        }
        head = prev; // prev is the new head
        cout << "List reversed.\n";
    }

    // 7. search for a value; returns 1-based position, or -1 if not found
    int searchValue(int value) const {
        Node* current = head;
        int position = 1;
        while (current != nullptr) {
            if (current->data == value) {
                return position;
            }
            current = current->next;
            position++;
        }
        return -1;
    }
};

int main() {
    LinkedList list;
    int choice;

    do {
        cout << "\n Singly Linked List Menu \n";
        cout << "1. Insert at head\n";
        cout << "2. Insert at 3rd position\n";
        cout << "3. Display list\n";
        cout << "4. Delete last node\n";
        cout << "5. Count nodes\n";
        cout << "6. Reverse list\n";
        cout << "7. Search for a value\n";
        cout << "8. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                cout << "Enter value to insert at head: ";
                cin >> value;
                list.insertAtHead(value);
                break;
            }
            case 2: {
                int value;
                cout << "Enter value to insert at 3rd position: ";
                cin >> value;
                list.insertAtThird(value);
                break;
            }
            case 3: {
                cout << "Current list: ";
                list.displayList();
                break;
            }
            case 4: {
                list.deleteLast();
                cout << "Updated list: ";
                list.displayList();
                break;
            }
            case 5: {
                cout << "Number of nodes: " << list.countNodes() << "\n";
                break;
            }
            case 6: {
                list.reverseList();
                cout << "Reversed list: ";
                list.displayList();
                break;
            }
            case 7: {
                int value;
                cout << "Enter value to search: ";
                cin >> value;
                int position = list.searchValue(value);
                if (position != -1) {
                    cout << "Value " << value << " found at position " << position << ".\n";
                } else {
                    cout << "Value " << value << " not found in the list.\n";
                }
                break;
            }
            case 8: {
                cout << "Exiting program.\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please enter a number between 1 and 8.\n";
            }
        }
    } while (choice != 8);

    return 0;
}