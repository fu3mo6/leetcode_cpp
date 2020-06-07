class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last_location;
        int result = 0, left = -1;
        
        for(int i = 0; i < s.size(); i ++){
            if(last_location.count(s[i])!=0)
            {
                left = max(left, last_location[s[i]]);
            }
            last_location[s[i]] = i;
            result = max(result, i-left);            
        }
        
        return result;
    }
};

// https://leetcode.com/problems/longest-substring-without-repeating-characters/description/