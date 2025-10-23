#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *prev, *next;
    Node(int v) {
        data = v;
        prev = NULL;
        next = NULL;
    }
};

class DLL {
    Node *head, *tail;
public:
    DLL() {
        head = NULL;
        tail = NULL;
    }

    ~DLL() {
        Node* t = head;
        while(t) {
            cout << "Deleting Node: " << t->data << endl;
            Node* nxt = t->next;
            delete t;
            t = nxt;
        }
        cout << "All nodes deleted successfully!" << endl;
    }

    void insertAtBegin(int val) {
        Node* n = new Node(val);
        if(!head) {
            head = tail = n;
            return;
        }
        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertAtEnd(int val) {
        Node* n = new Node(val);
        if(!tail) {
            head = tail = n;
            return;
        }
        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void insertAtPos(int pos, int val) {
        Node* n = new Node(val);
        if(pos == 1) {
            insertAtBegin(val);
            return;
        }
        Node* p = head;
        for(int i=1; p && i<pos-1; i++) p = p->next;
        if(!p) {
            insertAtEnd(val);
            return;
        }
        n->next = p->next;
        n->prev = p;
        if(p->next) p->next->prev = n;
        else tail = n;
        p->next = n;
    }

    void deleteFB() {
        if(!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* t = head;
        head = head->next;
        if(head) head->prev = NULL;
        else tail = NULL;
        delete t;
    }

    Node* search(int val) {
        Node* t = head;
        while(t) {
            if(t->data == val) {
                DisplayNode(t);
                return t;
            }
            t = t->next;
        }
        cout << "\nNode not found.\n" << endl;
        return NULL;
    }

    void DisplayNode(Node* n) {
        if(!n) {
            cout << "Node not found." << endl;
            return;
        }
        cout << "-----------------------------------------------------------------------------------\n";
        cout << "Prev Address\t|\tData\t|\tNext Address\t|\tNode Address\n";
        cout << "-----------------------------------------------------------------------------------\n";
        cout << n->prev << "\t|\t" << n->data << "\t|\t" << n->next << "\t|\t" << n << endl;
        cout << "-----------------------------------------------------------------------------------\n";
    }

    void Display() {
        if(!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* t = head;
        cout << "NULL <-> ";
        while(t) {
            cout << "[" << t->data << "] <-> ";
            t = t->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    DLL list;
    
    // Task 2: Insert elements
    list.insertAtBegin(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    
    // Insert at position 5
	list.insertAtPos(5, 50);
    list.Display();
    
    // Task 3: Delete from beginning
    list.deleteFB();
    list.Display();
    
    // Task 4: Search and display a specific node
    list.search(30);

    return 0;
}
