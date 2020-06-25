
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> tmp;
        queue<TreeNode*> bfs;
        TreeNode* node;
        
        if(!root)
            return result;
        
        bfs.push(root);
        while(!bfs.empty())
        {
            int len = bfs.size();
            tmp = {};
            for(int i=0; i<len; i++)
            {
                node = bfs.front();
                bfs.pop();
                
                tmp.push_back(node->val);
                if(node->left)
                    bfs.push(node->left);
                if(node->right)
                    bfs.push(node->right);
            }
            result.push_back(tmp);
        }
        
        return result;
    }
};

// https://leetcode.com/problems/binary-tree-level-order-traversal/description/