class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int left = 0;
        int right = 1;
        int result = 1;
        
        if(nums.size()==0)
            return 0;
        
        while(right < nums.size()){
            if(nums[right] > nums[right - 1]){
                right ++;
            }
            else {
                result = max(right-left, result);
                left = right;
                right++;
            }
        }
        result = max(right-left, result);
        return result;        
    }
};

// https://leetcode.com/problems/longest-continuous-increasing-subsequence/description/
// O(n)