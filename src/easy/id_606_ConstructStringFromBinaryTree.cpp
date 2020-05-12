class Solution {
public:
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        
        string result;
        if(!t->left && !t->right){
            result = to_string(t->val);
        }
        else if(!t->left){
            result = to_string(t->val) + "()(" + tree2str(t->right) + ")";            
        }
        else if(!t->right){
            result = to_string(t->val) + "(" + tree2str(t->left) + ")";            
        }
        else {
            result = to_string(t->val) + "(" + tree2str(t->left) + ")(" + tree2str(t->right) + ")";
        }
        
        return result;
    }
};

// https://leetcode.com/problems/construct-string-from-binary-tree/description/