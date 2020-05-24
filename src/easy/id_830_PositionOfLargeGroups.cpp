class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        vector<vector<int>> result;
        int left = 0, right = 1;
        while(right < S.size())
        {
            if(S[left] == S[right]){
                right ++;
            }
            else {
                if(right - left > 2)
                    result.push_back({left, right-1});
                left = right;
                right ++;
            }
        }
        
        if(right - left > 2)
            result.push_back({left, right-1});
        
        return result;
    }
};

// https://leetcode.com/problems/positions-of-large-groups/description/
// O(n)