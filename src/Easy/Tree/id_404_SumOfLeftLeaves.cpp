class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {  
        return dfs(NULL, root);        
    }
    
    int dfs(TreeNode* parent, TreeNode* root){
        if(!root)
            return 0;
        
        if(!root->right && !root->left){
            if(parent && parent->left == root)
                return root->val;
            else
                return 0;
        }        
        else {
            return dfs(root, root->left) + dfs(root, root->right);
        }        
    }
};

// https://leetcode.com/problems/sum-of-left-leaves/description/
// #BinaryTree #dfs #recursive