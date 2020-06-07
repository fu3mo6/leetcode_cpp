class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        
        int result_left = 0, result_right = 0;
        int len=0;
        
        for(int i=0; i<s.size(); i++){
            len = max(expandPalindrome(s, i, i),expandPalindrome(s, i, i+1));
            
            if(len > result_right - result_left)
            {
                result_left = i - (len-1)/2;
                result_right = i + len/2;
            }
        }
        
        return s.substr(result_left, result_right-result_left+1);
    }
    
    int expandPalindrome(string s, int left, int right){
        while(left >= 0 && right < s.size() && s[left] == s[right])
        {
            left --;
            right ++;            
        }
        return right-left-1;
    }
};

// https://leetcode.com/problems/longest-palindromic-substring/description
// #N^2