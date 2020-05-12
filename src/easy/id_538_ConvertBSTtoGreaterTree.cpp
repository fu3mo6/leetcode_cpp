class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        int tmp = _convert_and_sumBST(root, 0);
        return root;
    }
    
    int _convert_and_sumBST(TreeNode* root, int parent_sum){
        int r_sum=0, sum=0, l_sum=0;
        
        if(!root)
            return 0;
        
        if(root->right){
            r_sum = _convert_and_sumBST(root->right, parent_sum);
        }
        
        if(root->left){
            l_sum = _convert_and_sumBST(root->left, root->val + r_sum + parent_sum);
        }
            
        sum = root->val + r_sum + l_sum;        
        root->val = root->val + r_sum + parent_sum;
        
        return sum;
    }
};

// https://leetcode.com/problems/convert-bst-to-greater-tree/description/
// #BinarySearchTree #OrderSearch