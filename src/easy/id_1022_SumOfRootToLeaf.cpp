class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        if(!root)
            return 0;
        
        return sumSubtree(root, 0);        
    }
    
    int sumSubtree(TreeNode* root, int current){
        if(!root)
            return 0;
        
        current = current*2 + root->val;
        
        if(!root->left && !root->right)
            return current;
        
        return sumSubtree(root->right, current) + sumSubtree(root->left,  current);
        
    }
};

// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/description/
// #OrderTriversal