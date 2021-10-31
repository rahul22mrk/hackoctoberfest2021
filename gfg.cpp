#include<bits/stdc++.h>
#include<string>
#include<algorithm>
#include<set>
#include<math.h>
#include<vector>
#define ll long long
#define repi(i,a,b) for(ll i=a;i<=b;i++)
#define repd(i,a,b) for(ll i=a;i>=b;i--)
#define cy cout<<"YES\n"
#define cn cout<<"NO\n"
#define MOD 1000000009
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define nl cout<<"\n"
#define cm cout<<"-1\n"
using namespace std;

struct Node{
    int key;
    Node *left;
    Node *right;
    Node(int k){
        key = k;
        left=right=NULL;
    }
};

void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);
    }
    return;
}

void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" ";
    }
    return;
}

void preorder(Node *root){
    if(root!=NULL){
        cout<<root->key<<" ";
        preorder(root->left);
        preorder(root->right);
    }
    return;
}

int height(Node *root){
    if(root==NULL) return 0;
    return max(height(root->left), height(root->right))+1;
}

int main()
{   
    Node *root=new Node(10);
    root->left=new Node(20);
    root->right=new Node(30);
    root->left->left=new Node(40);
    root->right->left=new Node(50);
    root->right->right=new Node(60);
    cout<<"height: ";
    cout<<height(root);
    /*cout<<"inorder ";
    inorder(root);
    cout<<"\npreorder ";
    preorder(root);
    cout<<"\npostorderorder ";
    postorder(root);*/
    
}