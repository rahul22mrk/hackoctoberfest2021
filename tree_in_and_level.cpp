#include <bits/stdc++.h>
using namespace std;

class tree{
	public :
		int data;
		tree* left;
		tree* right;

		tree (int val){
			data = val;
			left = right = NULL;
		}
};

class tree* build_tree_helper (int in[], int level[], int inS, int inE, int i, int n){
	if (inS > inE)	return NULL;

	int rootdata = level[i];
	int rootindex = -1;
	for (int i=inS ; i<inE ; ++i){
		if (in[i] == rootdata){
			rootindex = i;
			break;
		}
	}

	int linS = inS;
	int linE = rootindex - 1;
	int li = 2 * i + 1;

	int rinS = rootindex + 1;
	int rinE = inE;
	int ri = 2 * i + 2;

	class tree* root = new tree(rootdata);

	if (li <= n){
		root->left = build_tree_helper (in, level, linS, linE, li, n);
	}
	if (ri <= n){
		root->right = build_tree_helper (in, level, rinS, rinE, ri, n);
	}

	return root;
}

class tree* build_tree (int in[], int level[], int size){
	return build_tree_helper (in, level, 0, size-1, 0, size-1);
}

void print (class tree* root){
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
	int level[] = {1,2,3,4,5,6,7};

	class tree* root = build_tree (in, level, 7);
	print (root);
	cout << "\n\n";
	
	return 0;
}