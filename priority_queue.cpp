#include <iostream>

using namespace std;

struct node {
    int value;
    int priority;
    node* next;

    node(int val, int p) : value(val), priority(p), next(nullptr) {}
};

class priority_queue {
private:
    node* head;
    void add_elem(int v, int p);
    void del_elem(int v);

public:
    priority_queue() {
        head = nullptr;
    }
    ~priority_queue() = default;
    void add_element(int value, int priority) {add_elem(value, priority);}
    void delete_element(int check_value) {del_elem(check_value);}
    void peak();
    void print();

};

void priority_queue::peak() {
    cout << "\nTop element with highest priority is " << head->value << ".\n";
}

void priority_queue::add_elem(int v, int p) {
    node* temp = new node(v, p);

    if (head == nullptr) {
        head = temp;
        return;
    }

    else if (head->priority < temp->priority) {
        temp->next = head;
        head = temp;
        return;
    }
    node* cur = head;

    while (cur->next) {
        if (cur->next->priority < temp->priority) {
            temp->next = cur->next;
            cur->next = temp;
            break;
        }
        cur = cur->next;
    }

    if (!cur->next) {
        cur->next = temp;
    }
}

void priority_queue::del_elem(int v) {
    if (v == head->value) {
        node* temp = head;
        head = temp->next;
        free(temp);
        return;
    }

    node* cur = head;

    while (cur->next) {
        if (cur->next->value == v) {
            node* temp = cur->next;
            if (!temp->next) {
                cur->next = nullptr;
                free(temp);
                break;
            }
            cur->next = temp->next;
            free(temp);
            break;
        }
        cur = cur->next;
    }
}

void priority_queue::print() {
    node* cur = head;

    while (cur) {
        cout << cur->value << "  ";
        cur = cur->next;
    }

    cout << "\n";
}

int main()
{
    priority_queue p = {};
    int check = 0;
    do {
        cout << "\n\n\tChoose an option from the following:\n";
        cout << "\n\t1.\tInsert an element.\n";
        cout << "\t2.\tDelete an element.\n";
        cout << "\t3.\tPeak element.\n";
        cout << "\t4.\tPrint Queue.\n";
        cout << "\n\t\tAny other key to exit.\n> ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                int value;
                int priority;
                cout << "\nEnter the element to be inserted : ";
                cin >> value;
                cout << "\nEnter the priority of the element : ";
                cin >> priority;
                p.add_element(value, priority);
                break;

            case 2:
                int val;
                cout << "\nEnter the element to be deleted : ";
                cin >> val;
                p.delete_element(val);
                break;

            case 3:
                p.peak();
                break;

            case 4:
                p.print();
                break;
                
            default:
                check = 1;
                break;
        }
    }while (check == 0);

    return 0;
}