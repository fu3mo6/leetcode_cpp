class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int result=0;
        
        int left=0, mid=0, tmp;
        
        left = 0;
        for(int i=1; i<nums.size(); i++){
            tmp = nums[i] - nums[i-1];
            
            switch(tmp){
                case 0:
                    break;
                case 1:
                    if(mid==0)
                        mid = i;
                    else {
                        result = max(result, i-left);
                        left = mid;
                        mid = i;
                    }
                    break;
                    
                default: // tmp >=2
                    if(mid != 0)
                        result = max(result, i-left);
                    left = i;
                    mid = 0;
            }
        }
        
        if(mid != 0){
            tmp = nums.size();
            result = max(result, tmp-left);
        }
        return result;
    }
};

// https://leetcode.com/problems/longest-harmonious-subsequence/description/
// #Subsequence