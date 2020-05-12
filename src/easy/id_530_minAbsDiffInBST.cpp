class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        int prev = -1;
        return traversal(root, prev);
    }
    
    int traversal(TreeNode* root, int& prev){
        int result = INT_MAX;
        if(!root)
            return INT_MAX;
        
        result = min(result, traversal(root->left, prev));
        if(prev>=0) // not root
            result = min(result, root->val - prev);
        
        prev = root->val;
        result = min(result, traversal(root->right, prev));
        return result;
    }
};


// https://leetcode.com/problems/minimum-absolute-difference-in-bst/description/
// #BinarySearchTree #OrderSearch