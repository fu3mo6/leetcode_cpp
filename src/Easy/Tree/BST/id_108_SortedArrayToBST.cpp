
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)
            return NULL;
        
        return _sortedArrayToBST(nums, 0, nums.size());
    }
    
    TreeNode* _sortedArrayToBST(vector<int>& nums, int left, int right)
    {
        if(left >= right)
            return NULL;
        
        int mid = (left + right)/2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = _sortedArrayToBST(nums, left, mid);
        root->right = _sortedArrayToBST(nums, mid+1, right);
        return root;
    }
};

// https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
// #BinarySearchTree #Recursion