class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode* root = NULL;
        
        if(t1 && t2){
            root = new TreeNode(t1 -> val + t2 -> val);
            root->left = mergeTrees(t1->left, t2->left);
            root->right = mergeTrees(t1->right, t2->right);
            return root;
        }
        
        return t1? t1 : t2;
    }
    
};

// https://leetcode.com/problems/merge-two-binary-trees/description/
// #ordertriveral