class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(!root)
            return NULL;
        
        // Find new root
        while(root->val < L || root->val > R)
        {
            if(root->val < L){
                root = root->right;
            }
            if(root->val > R){
                root = root->left;
            }
        }
        
        TreeNode* iter = root;
        while(iter->right)
        {
            if(iter->right->val > R){
                iter ->right = iter -> right -> left;
            }
            else {
                iter = iter -> right;
            }
        }
        
        iter = root;
        while(iter->left)
        {
            if(iter->left->val < L){
                iter ->left = iter -> left -> right;
            }
            else {                
                iter = iter -> left;
            }
        }       
        
        return root;
    }    
};

// https://leetcode.com/problems/trim-a-binary-search-tree/description/
// #ordertriversal