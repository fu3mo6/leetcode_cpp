class Solution {
public:
    bool backspaceCompare(string S, string T) {
        int S_len, T_len;
        S_len = remove_back(S);
        T_len = remove_back(T);
        
        if(S_len != T_len)
            return false;
        
        for(int i=0; i<S_len; i++){
            if(S[i] != T[i])
                return false;
        }
        return true;
    }
    
    int remove_back(string& str){
        int left = 0, right = 0;
        while(right<str.size()){
            if(str[right] == '#'){
                right++;
                left = max(0, left-1);
            }
            else {
                str[left] = str[right];
                left++;
                right++;
            }
        }      
        return left;        
    }
};

// https://leetcode.com/problems/backspace-string-compare/description/
// #CheckCornerCase