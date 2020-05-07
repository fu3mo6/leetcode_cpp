class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> loc(26,-1);
        int result = s.size();
        
        for(int i=0; i<s.size(); i++){
            if(loc[s[i]-'a'] == -1){
                loc[s[i]-'a'] = i;
            }
            else {
                loc[s[i]-'a'] = -2; // repeated                
            }
        }
        
        for(int i=0; i<26; i++){
            if(loc[i] >= 0){
                result = min(result, loc[i]);
            }
        }
        
        return result==s.size()? -1:result;
    }
};

// https://leetcode.com/problems/first-unique-character-in-a-string/description/
// #asciitable