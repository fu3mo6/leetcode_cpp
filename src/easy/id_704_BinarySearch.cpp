class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size();
        int mid;
        
        while(left < right)
        {
            mid = (left + right)/2;
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid;
            }
            else
                return mid;
        }
        return -1;
    }
};

// https://leetcode.com/problems/binary-search/description/