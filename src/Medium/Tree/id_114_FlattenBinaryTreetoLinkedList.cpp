class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* n = _flatten(root);
    }
    
    TreeNode* _flatten(TreeNode* root){
        TreeNode *n1, *n2;
        
        if(!root)
            return NULL;
        
        n1 = _flatten(root->left);
        n2 = _flatten(root->right);
        
        if(n1) {
            n1 -> right = root -> right;
            root->right = root -> left;
            root->left = NULL;
        }
        
        if(n2)
            return n2;
        else if(n1)
            return n1;
        else return root;
    }
};

// https://leetcode.com/problems/flatten-binary-tree-to-linked-list/description/