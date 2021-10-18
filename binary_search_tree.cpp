#include <bits/stdc++.h>

using namespace std;

struct node {
    int data;
    node* left;
    node* right;
    node (int val): data(val), left(nullptr), right(nullptr) {}
};

class bst {
private:
    node* root;
    void insert(node* treenode, int data);
    int getheight(node* treenode);
    bool isbalanced(node* treenode);
    void deletebst(node* treenode);
    void inorder(node* treenode);
    void preorder(node* treenode);
    void postorder(node* treenode);
    int minelement(node* treenode);
    int maxelement(node* treenode);

public:
    bst() : root(nullptr) {}    
    ~bst() {delete_bst();}

    void insert_data(int data) {insert(root, data);}
    int get_height() {return getheight(root);}
    int max_element() {return maxelement(root);}
    int min_element() {return minelement(root);}
    void delete_bst() {deletebst(root);}
    bool is_balanced() {return isbalanced(root);}
    void inorder() {inorder(root);}
    void preorder() {preorder(root);}
    void postorder() {postorder(root);}
};

void bst::insert(node* treenode, int val) {
    if (!treenode) {
        treenode = new node(val);
        root = treenode;
    }
    else {
        if (val < treenode->data) {
            if (!treenode->left) {
                node* temp = new node(val);
                treenode->left = temp;
            }
            else 
                insert(treenode->left, val);
        }

        else {
            if (!treenode->right) {
                node* temp = new node(val);
                treenode->right = temp;
            }
            else 
                insert(treenode->right, val);
            
        }
    }
}

bool bst::isbalanced(node* treenode) {
    if (!treenode) {
        return false;
    }

    int rh = getheight(treenode->right);
    int lh = getheight(treenode->left);

    if (abs(lh - rh) > 1) {
        return false;
    }

    return true;
}

int bst::getheight(node* treenode) {
    if (!treenode) {
        return 0;
    }

    return (max(getheight(treenode->left), getheight(treenode->right)) + 1);
}

void bst::deletebst(node* treenode) {
    if (!treenode) {
        return;
    }

    node* temp = treenode;
    node* ltemp = treenode->left;
    node* rtemp = treenode->right;

    delete temp;
    deletebst(ltemp);
    deletebst(rtemp);
    root = nullptr;
}

void bst::inorder(node* treenode) {
    if (!treenode) {
        return;
    }

    inorder(treenode->left);
    cout << treenode->data << "\t";
    inorder(treenode->right);
}

void bst::preorder(node* treenode) {
    if (!treenode) {
        return;
    }

    cout << treenode->data << "\t";
    preorder(treenode->left);
    preorder(treenode->right);
}

void bst::postorder(node* treenode) {
    if (!treenode) {
        return;
    }

    postorder(treenode->left);
    postorder(treenode->right);
    cout << treenode->data << "\t";
}

int bst::minelement(node* treenode) {
    node* cur = root;
    while (cur->left) {
        cur = cur->left;
    }

    return cur->data;
}

int bst::maxelement(node* treenode) {
    node* cur = root;
    while (cur->right) {
        cur = cur->right;
    }

    return cur->data;
}

int main() {
    bst b = {};
    int check = 0;
    do {
        cout << "\n\n\tChoose an option from the following:\n";
        cout << "\n\t1.\tIs tree balanced?\n";
        cout << "\t2.\tInsert an element.\n";
        cout << "\t3.\tHeight of tree.\n";
        cout << "\t4.\tInorder.\n";
        cout << "\t5.\tPreorder.\n"; 
        cout << "\t6.\tPostorder.\n";
        cout << "\t7.\tMinimum element.\n";
        cout << "\t8.\tMaximum element.\n";
        cout << "\t9.\tDelete list.\n";
        cout << "\n\t\tAny other key to exit.\n> ";
        int choice;
        cin >> choice;
        int value;

        switch (choice) {
            case 1:
                if (b.is_balanced() == false) {
                    cout << "\nThe tree is not Balanced.\n";
                }
                else {
                    cout << "\nThe tree is Balanced.\n";
                }
                break;
            case 2:
                cout << "\nEnter the element to be inserted : ";
                cin >> value;
                b.insert_data(value);
                break;
            case 3:
                cout << "\nHeight of the tree is " << b.get_height() << ".\n";
                break;
            case 4:
                cout << "\nInorder : "; 
                b.inorder();
                cout << ".\n";
                break;
            case 5:
                cout << "\nPreorder : ";
                b.preorder();
                cout << ".\n";
                break;
            case 6:
                cout << "\nPostorder : ";
                b.postorder();
                cout << ".\n";
                break;
            case 7:
                cout << "\nMinimum element is " << b.min_element() << ".\n";
                break;
            case 8:
                cout << "\nMaximum element is " << b.max_element() << ".\n";
                break;
            case 9:
                cout << "\nDeleting the BST.\n";
                b.delete_bst();
                break;
            default:
                check = 1;
                break;
        }
    }while (check == 0);

    return 0;
}