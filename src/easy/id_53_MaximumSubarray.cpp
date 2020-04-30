class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        int result = INT_MIN;
        
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i]>0)
                nums[i+1]+=nums[i];
        }
        for(int i=0; i<nums.size(); i++){
            result = max(result, nums[i]);
        }
        
        return result;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty())
            return 0;
        
        vector<int> result = _maxSubArray(nums, 0, nums.size()-1);
        return result[3];
    }
    
    vector<int> _maxSubArray(vector<int>& nums, int left, int right){
        // left & right: count nums[left:right]
        // result: left_sum, right_sum, total_sum, max_sum
        
        vector<int> result(4,0);
        if(left == right){
            result[0] = nums[left];
            result[1] = nums[left];
            result[2] = nums[left];
            result[3] = nums[left];
            return result;
        }
        
        int mid = (left + right) / 2;
        vector<int> left_result, right_result;
        left_result = _maxSubArray(nums, left, mid);
        right_result = _maxSubArray(nums, mid+1, right);
        
        result[0] = max(left_result[0], left_result[2] + right_result[0]);
        result[1] = max(right_result[1], right_result[2] + left_result[1]);
        result[2] = left_result[2] + right_result[2];
        result[3] = max(max(left_result[3], right_result[3]), left_result[1]+right_result[0]);
        
        return result;
    }
};

// https://leetcode.com/problems/maximum-subarray/description/
// #ContiSubArray #DynamicProgramming