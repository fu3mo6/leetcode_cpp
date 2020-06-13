class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=2)
            return nums.size();
        
        int left = 1, right = 2;
        while(right < nums.size()){
            if(nums[right] == nums[left] && nums[right] == nums[left-1]){
                right++;
            }
            else{
                nums[left+1] = nums[right];
                right++;
                left++;
            }
        }
        return left+1;        
    }
};

// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/
