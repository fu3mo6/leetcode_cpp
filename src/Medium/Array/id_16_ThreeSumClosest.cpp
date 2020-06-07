class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left, right, goal;
        int result = 0, diff = INT_MAX;
        
        for(int fixed=0; fixed < nums.size()-2; fixed++ ){
            left = fixed + 1;
            right = nums.size()-1;
            goal = target - nums[fixed];
            while(left < right){
                if(abs(nums[left] + nums[right] - goal) < diff){
                    result = nums[left] + nums[right] + nums[fixed];
                    diff = abs(nums[left] + nums[right] - goal);
                }
                
                if(nums[left]+nums[right] < goal)
                    left++;
                else
                    right--;
            }
        }
        
        return result;
        
    }
};

// https://leetcode.com/problems/3sum-closest/description/
// #Sort #O(n^2)