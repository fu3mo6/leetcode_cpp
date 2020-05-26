class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0, right = 1;
        if(nums.size()==0) return 0;
        while(right < nums.size()){
            if(nums[right] == nums[left]){
                right++;
            }
            else {
                nums[left+1] = nums[right];
                left++;
                right++;
            }
        }
        return left+1;
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
// #twoid
