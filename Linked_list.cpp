#include <iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

class linkedList {
private:
    node *head;

public:
    linkedList() {
        head = nullptr;
    }

    static node *new_node(int value);
    int count();
    void insert_at_begin(int value);
    void append(int value);
    void add_element(int value, int place);
    void delete_first_node();
    void delete_end_node();
    void delete_node(int value);
    void print();
};

node * linkedList::new_node(int value) {
    node *n_node = new node;
    n_node->data = value;
    n_node->next = nullptr;
    return n_node;
}

int linkedList::count() {
    auto *cur = new node;
    cur = head;
    int count = 0;
    while (cur) {
        cur = cur->next;
        count ++;
    }
    return count;
}

void linkedList::insert_at_begin(int value) {
    node *node = new_node(value);
    node->next = head;
    head = node;
}

void linkedList::append(int value) {
    node *end = new node;
    end = head;
    if (end == nullptr) {
        insert_at_begin(value);
    }
    else {
        while (end->next) {
            end = end->next;
        }
        auto node = new_node(value);
        end->next = node;
    }
}

void linkedList::add_element(int value, int place) {
    node *n = new_node(value);
    if (place == 1 || head == nullptr) {
        insert_at_begin(value);
    }
    else {
        node *cur = new node;
        cur = head;
        int p = 2;
        while (cur && p != place) {
            cur = cur->next;
            p ++;
        }
        if (cur) {
            n->next = cur->next;
            cur->next = n;
        }
        else {
            append(value);
        }
    }
}

void linkedList::delete_first_node() {
    auto *temp = new node;
    temp = head;
    head = head->next;
    free(temp);
}

void linkedList::delete_end_node() {
    auto *cur = head;
    while (cur->next->next) {
        cur = cur->next;
    }

    auto *temp = new node;
    temp = cur->next;
    cur->next = nullptr;
    free(temp);
}

void linkedList::delete_node(int value) {
    if (head->data == value) {
        delete_first_node();
        return;
    }

    node *cur = head;
    while (cur->next != nullptr || cur->next->data != value) {
        cur = cur->next;
    }
    if (cur->next->data == value) {
        cur->next = cur->next->next;
        return;
    }
    cout << "\nNo such element in the list.\n";
}

void linkedList::print() {
    node * cur = head;
    if (cur == nullptr) {
        cout << "\nList is empty.\n";
        return;
    }
    cout << "\nPrinting list : \n";
    while (cur) {
        cout << cur->data << "\t";
        cur = cur->next;
    }
    cout << "\nWith " << head->data << " as head value.";
}

int main()
{
    int check = 0;
    linkedList list = {};
    do {
        cout << "\n\n\tChoose an option from the following:\n";
        cout << "\n\t1.\tCount of elements.\n";
        cout << "\t2.\tInsert element at beginning.\n";
        cout << "\t3.\tInsert element in between.\n";
        cout << "\t4.\tInsert element at the end.\n";
        cout << "\t5.\tDelete first element.\n";
        cout << "\t6.\tDelete last element.\n";
        cout << "\t7.\tDelete an element.\n";
        cout << "\t8.\tPrint List.\n";
        cout << "\n\t\tAny other key to exit.\n> ";
        int choice;
        cin >> choice;
        int value;

        switch (choice) {
            case 1:
                cout << "\nThe list has " << list.count() << " elements.\n";
                break;

            case 2:
                cout << "\nEnter the element to be entered : ";
                cin >> value;
                list.insert_at_begin(value);
                break;
            case 3:
                cout << "\nEnter the element to be entered : ";
                cin >> value;
                cout << "\nEnter the place (where the element is to be added) : ";
                int in_place;
                cin >> in_place;
                list.add_element(value, in_place);
                break;
            case 4:
                cout << "\nEnter the element to be entered : ";
                cin >> value;
                list.append(value);
                break;
            case 5:
                list.delete_first_node();
                cout << "\nDeleted first node.\n";
                break;
            case 6:
                list.delete_end_node();
                cout << "\nDeleted Last node.\n";
                break;
            case 7:
                cout << "\nEnter the element to be deleted : ";
                cin >> value;
                list.delete_node(value);
                break;
            case 8:
                list.print();
                break;
            default:
                check = 1;
                break;
        }
    } while (check == 0);
    return 0;
}