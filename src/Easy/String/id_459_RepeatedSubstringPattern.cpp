class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i=1; i<=s.size()/2; i++){
            if(s.size() % i != 0)
                continue;
            if(isSubstringPattern(s, i, i-1))
                return true;
        }
        return false;
    }
    
    bool isSubstringPattern(string& s, int s_idx, int p_end)
    {
        // check if s[s_idx:] is repeated copy of s[0:p_end]        
        if(s_idx==s.size())
            return true;
        int i = s_idx;
        int j = 0;
        while(j <= p_end){
            if(s[i] != s[j])
                return false;
            i++;
            j++;
        }
        return isSubstringPattern(s,i,p_end);
    }
};

// https://leetcode.com/problems/repeated-substring-pattern/description/