class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return _isValidBST(root, NULL, NULL);
    }
    
    bool _isValidBST(TreeNode* root, const TreeNode* left, const TreeNode* right)
    {
        if(!root)
            return true;
        else if(left && root->val <= left->val)
            return false;
        else if(right && root->val >= right->val)
            return false;
        else if(!_isValidBST(root->left, left, root))
            return false;
        else if(!_isValidBST(root->right, root, right))
            return false;
        else
            return true;
        
    }
};

// https://leetcode.com/problems/validate-binary-search-tree/description/