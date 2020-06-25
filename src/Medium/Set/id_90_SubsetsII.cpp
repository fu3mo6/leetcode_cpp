class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;        
        sort(nums.begin(), nums.end());
        
        result.push_back({});
        
        int i = 0, cnt;
        while(i < nums.size()){
            cnt = 1;
            while(i+1 < nums.size() && nums[i] == nums[i+1]){
                i++;
                cnt++;
            }
            addSubsets(result, nums[i], cnt);
            i++;
        }
        
        return result;
    }
    
    void addSubsets(vector<vector<int>>& result, int newnum, int cnt){
        int len = result.size();        
        vector<int> current = {};
        
        for(int i=0; i<len; i++){
            current = result[i];
            for(int j=0; j<cnt; j++){
                current.push_back(newnum);
                result.push_back(current);                
            }
        }
        
    }
};

// https://leetcode.com/problems/subsets-ii/description/