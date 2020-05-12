class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return depth(root)>=0;
    }
    int depth(TreeNode* root){
        if(!root)
            return 0;
        
        int depth_l = depth(root->left);
        int depth_r = depth(root->right);
        
        if(depth_l==-1 || depth_r==-1 || abs(depth_l-depth_r)>1)
            return -1;
        
        return max(depth_l, depth_r)+1;
    }
};

// https://leetcode.com/problems/balanced-binary-tree/description/
// #BinaryTree