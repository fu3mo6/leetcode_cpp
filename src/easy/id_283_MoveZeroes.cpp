class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zero_cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0)
                zero_cnt++;
            else if (zero_cnt != 0) {     
                nums[i-zero_cnt] = nums[i];
                nums[i] = 0;
            }
        }
    }
};

// https://leetcode.com/problems/move-zeroes/description/
// #inplace