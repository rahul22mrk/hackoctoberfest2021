#include <bits/stdc++.h>

using namespace std;

struct node {
    int key;
    node* left;
    node* right;
    int height;

    node (int k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class avl {
private:
    node* root;

    int height(node* n);
    int max(int a, int b);
    int get_balance(node* n);
    node* min_node(node* n);
    node* right_rotate(node* y);
    node* left_rotate(node* y);
    node* add(node* n, int k);
    node* delete_node(node* n, int k);
    void preorder(node* n);
    void delete_avl(node* n);

public:
    avl() {root = nullptr;}
    ~avl() {delete_avl(root);}

    void insert(int val) {root = add(root, val);}
    void display() {preorder(root);}
    void delete_n(int key) {delete_node(root, key);}
};

int avl::height(node* n) {
    if (n == nullptr) {
        return 0;
    }

    return n->height;
}

int avl::max(int a, int b) {
    return (a > b) ? a : b;
}

int avl::get_balance(node* n) {
    if (n == nullptr) {
        return 0;
    }

    return (height(n->left) - height(n->right));
}

node* avl::min_node(node* x) {
    node* n = x;
    while (n->left) {
        n = n->left;
    }

    return n;
}

node* avl::right_rotate(node* y) {
    node* x = y->left;
    node* temp = x->right;

    x->right = y;
    y->left = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return x;
}

node* avl::left_rotate(node* y) {
    node* x = y->right;
    node* temp = x->left;

    x->left = y;
    y->right = temp;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return x;
}

node* avl::add(node* n, int k) {
    if (n == nullptr) {
        return new node(k);
    }

    if (k > n->key) 
        n->right = add(n->right, k);
    else if (k < n->key) 
        n->left = add(n->left, k);
    else
        return n;

    n->height = 1 + max(height(n->left), height(n->right));

    int balance = get_balance(n);

    if (balance > 1 && k < n->left->key)
        return right_rotate(n);

    if (balance < -1 && k > n->right->key) 
        return left_rotate(n);

    if (balance > 1 && k > n->left->key) {
        n->left = left_rotate(n->left);
        return right_rotate(n);
    }

    if (balance < -1 && k < n->right->key) {
        n->right = right_rotate(n->right);
        return left_rotate(n);
    }

    return n;
}

node* avl::delete_node(node* n, int key) {
    if (n == nullptr) 
        return n;

    if (key < n->key) 
        n->left = delete_node(n->left, key);

    else if (key > n->key) 
        n->right = delete_node(n->right, key);

    else {
        if (!n->left || !n->right) {
            node* temp = root->left ? root->left : root->right;
            if (temp == nullptr) {
                temp = n;
                n = nullptr;
            }
            else 
                *n = *temp;

            free(temp);
        }
        else {
            node* temp = min_node(n->right);
            n->key = temp->key;
            n->right = delete_node(n->right, temp->key);
        }
    }

    if (n == nullptr) 
        return n;

    n->height = 1 + max(height(n->left), height(n->right));

    int balanceFactor = get_balance(n);
        
    if (balanceFactor > 1) {
        if (get_balance(n->left) >= 0) {
            return right_rotate(n);
        }
        else {
            n->left = left_rotate(n->left);
            return right_rotate(n);
        }
    }
    if (balanceFactor < -1) {
        if (get_balance(n->right) <= 0) {
            return left_rotate(n);
        }
        else {
            n->right = right_rotate(n->right);
            return left_rotate(n);
        }
    }
    return n;
}

void avl::preorder(node* cur) {
    if (cur) {
        cout << cur->key << "\t";
        preorder(cur->left);
        preorder(cur->right);
    }
}

void avl::delete_avl(node* n) {
    if (!n) {
        return;
    }

    node* temp = n;
    node* ltemp = n->left;
    node* rtemp = n->right;

    delete temp;
    delete_avl(ltemp);
    delete_avl(rtemp);
    root = nullptr;
}

int main()
{
    avl a = {};
    int check = 0;
    do {
        cout << "\n\n\tChoose an option from the following:\n";
        cout << "\n\t1.\tAdd new element.\n";
        cout << "\t2.\tDisplay tree as preorder.\n";
        cout << "\t3.\tDelete specific element.\n";
        cout << "\n\t\tAny other key to exit.\n> ";
        int choice;
        cin >> choice;
        int value;

        switch (choice) {
            case 1:
                cout << "\nEnter the element to be inserted.\n";
                cin >> value;
                a.insert(value);
                break;
            case 2:
                cout << "\nElements in tree are :\n";
                a.display();
                break;
            case 3:
                cout << "\nEnter the element to be deleted.\n";
                cin >> value;
                a.delete_n(value);
                break;
            default:
                check = 1;
                break;
        }
    }while (check == 0);

    return 0;
}