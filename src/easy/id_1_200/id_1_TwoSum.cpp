class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;
        vector<int> result;
        
        for(int i=0; i<nums.size(); i++){
            if(hash.count(target - nums[i])==0){
                hash[nums[i]] = i;
            }
            else {
                result.push_back(hash[target - nums[i]]);
                result.push_back(i);
                break;
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/two-sum/description/
// #unordered_map

