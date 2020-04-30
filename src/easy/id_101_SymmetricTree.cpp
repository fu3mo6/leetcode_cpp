class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(!root)
            return true;
        return _isSymmetric(root->left, root->right);
    }
    
    bool _isSymmetric(TreeNode *n1, TreeNode *n2){        
        if(!n1 && !n2)
            return true;        
        if(!n1 || !n2)
            return false;
        if(n1->val != n2->val)
            return false;
        
        return _isSymmetric(n1->right, n2->left) && _isSymmetric(n1->left, n2->right);       
    }
};

// https://leetcode.com/problems/symmetric-tree/description/
// #BinaryTree