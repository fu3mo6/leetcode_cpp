class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> list1, list2;
        
        _getleaf(root1, list1);
        _getleaf(root2, list2);
        
        if(list1.size()!=list2.size())
            return false;
        
        for(int i=0; i<list1.size(); i++){
            if(list1[i] != list2[i])
                return false;
        }
        return true;
    }
    
    void _getleaf(TreeNode* root, vector<int> &leaflist){
        if(!root->right && !root->left)
            leaflist.push_back(root->val);
        
        if(root->left)
            _getleaf(root->left, leaflist);
                
        if(root->right)
            _getleaf(root->right, leaflist);

    }
};

// https://leetcode.com/problems/leaf-similar-trees/description/
// #OrderTriversal