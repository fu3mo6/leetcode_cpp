/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        // inorder:   left->root->right
        // postorder: left->right->root
        
        return _buildTree(inorder, postorder, 0, inorder.size()-1, 0, postorder.size()-1);
    }    
    
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, 
                         int in_left, int in_right, int post_left, int post_right) 
    {
        // inorder: left->root->right
        // postorder: left->right->root
        
        if(in_left > in_right || post_left > post_right)
            return NULL;
        
        TreeNode* root;
        int in_mid, post_mid;
        for(int i = in_left; i <= in_right; i++){
            if(inorder[i] == postorder[post_right]){
                in_mid = i;
                break;
            }
        }
        post_mid = in_mid - in_left + post_left;
        
        root = new TreeNode(postorder[post_right]);
        root->left = _buildTree(inorder, postorder, in_left, in_mid - 1, post_left, post_mid - 1);
        root->right = _buildTree(inorder, postorder, in_mid + 1, in_right, post_mid, post_right - 1);
        
        return root;
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/