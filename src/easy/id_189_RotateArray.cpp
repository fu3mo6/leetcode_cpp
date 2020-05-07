
class Solution {
public:
    void reverse(vector<int> &nums, int left, int right)
    {
        int tmp;
        while(left < right)
        {
            tmp = nums[left];
            nums[left] = nums[right];
            nums[right] = tmp;
            
            left++;
            right--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n)
            k=k%n;

        reverse(nums,0,n-k-1);
        reverse(nums,n-k,n-1);
        reverse(nums,0,n-1);
    }
};

// https://leetcode.com/problems/rotate-array/description/
// #RotateReverseTechnique