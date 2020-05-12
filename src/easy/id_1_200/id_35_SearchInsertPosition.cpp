class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left, mid, right;
        left = 0;
        right = nums.size();
        
        while(right>left){
            mid = (left + right)/2;
            if(target == nums[mid])
                return mid;
            else if(target < nums[mid])
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left, mid, right;
        left = 0;
        right = nums.size();
        return _searchInsert(nums, target, left, right)
    }
    
    int _searchInsert(vector<int>& nums, int target, int left, int right){
        int mid = (left + right)/2;
        
        if(left >= right)
            return left;
        
        if(nums[mid] == target)
            return mid;
        else if(target < nums[mid])
            return _searchInsert(nums, target, left, mid);
        else
            return _searchInsert(nums, target, mid+1, right);
    }
};

// https://leetcode.com/problems/search-insert-position/description/
// #BinarySearch #iteration #recursion