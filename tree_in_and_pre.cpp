#include <bits/stdc++.h>
using namespace std;

struct tree{
	int data;
	tree* left;
	tree* right;
};

struct tree* newnode (int val){
	struct tree* temp = new tree();
	temp->data = val;
	temp->left = temp->right = NULL;

	return temp;
}

struct tree* build_helper (int in[], int pre[], int inS, int inE, int preS, int preE){
	if (inS > inE)	return NULL;

	int rootdata = pre[preS];
	int rootindex = -1;
	for (int i=inS ; i<=inE ; ++i){
		if (in[i] == rootdata){
			rootindex = i;
			break;
		}
	}

	int linS = inS;
	int linE = rootindex - 1;
	int lpreS = preS + 1;
	int lpreE = linE - linS + lpreS;

	int rpreS = lpreE + 1;
	int rpreE = preE;
	int rinS = rootindex + 1;
	int rinE = inE;

	struct tree* root = newnode (rootdata);
	root->left = build_helper (in, pre, linS, linE, lpreS, lpreE);
	root->right = build_helper (in, pre, rinS, rinE, rpreS, rpreE);
	return root;
}

struct tree* build_tree (int in[], int pre[], int size){
	return build_helper (in, pre, 0, size-1, 0, size-1);
}

void print (struct tree* root){
	if (root){
		cout << root->data << " ";

		if (root->left)
		{
			print (root->left);
		}

		if (root->right){
			print (root->right);
		}
	}
}

int main()
{
	int in[] = {4,2,5,1,6,3,7};
	int pre[] = {1,2,4,5,3,6,7};

	struct tree* root = build_tree (in, pre, 7);
	print (root);
	return 0;
}