class Solution {
public:
    bool search(vector<int>& nums, int target) {
        return search_recur(nums, target, 0, nums.size()-1);
    }
    
    bool search_recur(vector<int>& nums, int target, int left, int right) {
        while (left <= right) {
            int mid = (left + right) / 2;
            if (target == nums[mid])
                return true;
                        
            // there exists rotation; left part of the array is sorted
            if (nums[mid] > nums[right]) {
                if (target < nums[mid] && target >= nums[left])
                    return search_recur(nums, target, left, mid-1);
                else
                    return search_recur(nums, target, mid+1, right);
            }
            // there exists rotation; right part of the array is sorted
            else if (nums[mid] < nums[left]) {
                if (target > nums[mid] && target <= nums[right])
                    return search_recur(nums, target, mid+1, right);
                else
                    return search_recur(nums, target, left, mid-1);
            }
            // has duplicate -> not sure, but "left" and "right" is impossible
            else if (nums[left] == nums[mid] && nums[mid] == nums[right]){
                return search_recur(nums, target, left + 1, right - 1);                
            }
            // no duplicate -> no rotation; just like normal binary search
            else {
                if (target < nums[mid])
                    return search_recur(nums, target, left, mid-1);
                else
                    return search_recur(nums, target, mid+1, right);
            }
        }
        return false;        
    }
};

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/