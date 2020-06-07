class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result(2,-1);
        if(nums.size() == 0)
            return result;
        
        result[0] = binarySearch_left(nums, target, 0, nums.size()-1);
        if(result[0] == -1){
            return result;
        }
        
        result[1] = binarySearch_right(nums, target, result[0], nums.size()-1);
        
        return result;
    }

    // first equal to target    
    int binarySearch_left(vector<int>& nums, int target, int left, int right){
        if(left >= right){
            if(nums[left] == target) return left;
            else if(left+1 < nums.size() && nums[left+1] == target) return left+1;
            else return -1;
        }
        
        int mid = (left+right)/2;
        if(nums[mid] >= target)
            return binarySearch_left(nums, target, left, mid-1);
        else
            return binarySearch_left(nums, target, mid+1, right);
    }
    
    // last equal to target    
    int binarySearch_right(vector<int>& nums, int target, int left, int right){
        if(left >= right){
            if(nums[left] == target) return left;
            else if(left-1 >= 0 && nums[left-1] == target) return left-1;
            else return -1;
        }
        
        int mid = (left+right)/2;
        if(nums[mid] > target)
            return binarySearch_right(nums, target, left, mid-1);
        else
            return binarySearch_right(nums, target, mid+1, right);
    }

};

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
// #BinarySearchEnhanced