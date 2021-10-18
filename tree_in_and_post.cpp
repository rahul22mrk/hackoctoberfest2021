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

struct tree* build_helper (int in[], int post[], int inS, int inE, int postS, int postE){
	if (inS > inE)	return NULL;

	int rootdata = post[postE];
	int rootindex = -1;
	for (int i=inS ; i<=inE ; ++i){
		if (in[i] == rootdata){
			rootindex = i;
			break;
		}
	}

	int linS = inS;
	int linE = rootindex - 1;
	int lpostS = postS;
	int lpostE = linE - linS + lpostS;

	int rinS = rootindex + 1;
	int rinE = inE;
	int rpostS = lpostE + 1;
	int rpostE = postE - 1;

	struct tree* root = newnode (rootdata);
	root->left = build_helper (in, post, linS, linE, lpostS, lpostE);
	root->right = build_helper (in, post, rinS, rinE, rpostS, rpostE);

	return root;
}

struct tree* build_tree (int in[], int post[], int size){
	return build_helper (in, post, 0, size-1, 0, size-1);
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
	int post[] = {4,5,2,6,7,3,1};

	struct tree* root = build_tree (in, post, 7);
	print (root);
	cout << "\n\n";
	return 0;
}