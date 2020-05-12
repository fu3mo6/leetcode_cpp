class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        
        queue<TreeNode*> bfs_order;
        TreeNode* node;
        int result = 0, qlen=0;
        bfs_order.push(root);
        
        while(!bfs_order.empty()){
            qlen = bfs_order.size();
            
            while(qlen >0){
                node = bfs_order.front();
                if(node->left){           
                    bfs_order.push(node->left);
                }
                if(node->right){
                    bfs_order.push(node->right);                
                }
                if(!node->left && !node->right)
                    break;
                
                bfs_order.pop();
                qlen --;
            }
                       
            result++;
            if(qlen != 0)
                break;
        }
        return result;
    }
};

// https://leetcode.com/problems/minimum-depth-of-binary-tree/description/
// #BFS #BinaryTree
