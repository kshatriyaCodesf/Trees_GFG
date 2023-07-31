
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)return NULL;
        if(!root->left and !root->right)
        {
            return root; 
        }
        TreeNode*left = invertTree(root->left);
        TreeNode*right = invertTree(root->right);
        
        root->left=right;
        root->right=left;
        
        return root ;
    }
};