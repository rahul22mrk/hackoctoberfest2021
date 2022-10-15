class Solution {
    int f(TreeNode *root, int &ans)
    {
        if(!root)
            return 0 ;
        int left = f(root->left , ans);
        int right = f(root->right, ans);
    
        ans = max( ans,1 + left + right);
        return 1 + max(left,right);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
      int ans = 0 ;
        f(root,ans);
        return --ans;
    }
};