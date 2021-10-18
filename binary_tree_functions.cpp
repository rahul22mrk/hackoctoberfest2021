#include <iostream> 

using namespace std;

struct node {
	int data;
	struct node *left, *right;
};

struct node *newnode(int data);

int max(int a, int b) { return (a > b) ? a : b; }

int height(struct node *node);

int getwidth(struct node *node, int level);

int getMaxWidth(struct node *root);

int diameter(struct node *tree) {
	if (tree == nullptr) {
		return 0;
	}

	int lheight = height(tree->left);
	int rheight = height(tree->right);

	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	return max(lheight + rheight + 1, 
			max(ldiameter, rdiameter));
}

int height(struct node *node) {
	if (node == nullptr) {
		return 0;
	}

	return (1 + max(height(node->left), height(node->right)));
}

struct node *newnode(int data) {
	struct node *newNode = new node;
	newNode->data = data;
	newNode->left = newNode->right = nullptr;

	return newNode;
}

int getMaxWidth(struct node *root) {
	int width;
	int maxWidth = 0;

	int h = height(root);

	for (int i = 0 ; i <= h ; i ++) {
		width = getwidth(root, i);
		if (width > maxWidth) {
			maxWidth = width;
		}
	}

	return maxWidth;
}

int getwidth(struct node *node, int level) {
	if (node == nullptr) {
		return 0;
	}

	if (level == 1) {
		return 1;
	}

	return (getwidth(node->left, level - 1) + getwidth(node->right, level - 1));
}

int main()
{
	struct node* root = newnode(1);
    root->left = newnode(2);
    root->right = newnode(3);
    root->left->left = newnode(4);
    root->left->right = newnode(5);
    
    cout << "Diameter of the given binary tree is " << diameter(root) << endl;
    cout << "Maximum width of the tree is " << getMaxWidth(root) << endl;
 
    return 0;
}