class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<int> tmp;
        vector<vector<int>> result;
        if(!root)
            return result;

        queue<TreeNode*> bfs_order;
        TreeNode* node;
        int qlen=0;
        bfs_order.push(root);
        while(!bfs_order.empty()){
            qlen = bfs_order.size();
            tmp.clear();
            while(qlen >0){
                node = bfs_order.front();
                if(node->left){           
                    bfs_order.push(node->left);
                }
                if(node->right){
                    bfs_order.push(node->right);                
                }
                bfs_order.pop();
                qlen --;
                tmp.push_back(node->val);
            }
            result.insert(result.begin(), tmp);
        }
        return result;
        
    }
};

// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/description/
// #BinaryTree #BFS #Queue