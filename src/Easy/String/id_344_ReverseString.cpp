class Solution {
public:
    string reverseString(string s) {
        char tmp;
        for(int i=0; i<s.size()/2; i++){
            tmp = s[i];
            s[i] = s[s.size()-1-i];
            s[s.size()-1-i] = tmp;
        }
        return s;
    }
};

// https://leetcode.com/problems/reverse-string/description/
// #inplace #reverse