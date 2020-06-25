class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        _inorderTraversal(root, result);
        return result;
    }
    
    void _inorderTraversal(TreeNode* root, vector<int>& result)
    {
        if(!root)
            return;
        
        _inorderTraversal(root->left, result);
        result.push_back(root->val);
        _inorderTraversal(root->right, result);
    }
};

class Solution {
public:
    // inorder: left->root->right
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> dfs;
        vector<int> result;
        
        if(!root) return result;
        
        TreeNode *next = NULL, *current = root;
        while(!dfs.empty() || current){
            if(current){
                dfs.push(current);
                current = current -> left;
            }
            else {
                next = dfs.top();
                dfs.pop();
                result.push_back(next->val);
                current = next -> right;
            }
        }
        return result;
    }
};
// https://leetcode.com/problems/binary-tree-inorder-traversal/description/