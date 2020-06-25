class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return _buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
    
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, 
                         int pre_left, int pre_right, int in_left, int in_right) 
    {
        // inorder:  left->root->right
        // preorder: root->left->right
        
        if(in_left > in_right || pre_left > pre_right)
            return NULL;
        
        int in_mid, pre_mid;
        // inorder[in_mid] = root
        // preorder[pre_mid + 1] = right
        
        for(int i = in_left; i <= in_right; i++){
            if(inorder[i] == preorder[pre_left]){
                in_mid = i;
                break;
            }
        }
        
        // in_mid - in_left = sizeof(left_tree)
        // -> pre_mid = pre_left + sizeof(left_tree)
        pre_mid = in_mid - in_left + pre_left;
        
        TreeNode* root;
        root = new TreeNode(preorder[pre_left]);
        root->left = _buildTree(preorder, inorder, pre_left+1, pre_mid, in_left, in_mid-1);
        root->right = _buildTree(preorder, inorder, pre_mid+1, pre_right, in_mid+1, in_right);
        
        return root;
    }
};

// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/