class Solution {
public:
    string reverseWords(string s) {
        string result = s;
        if(result.empty())
            return result;
                
        size_t left = 0, right = result.find(" ");
        
        while(right != string::npos){            
            _reverseWords(result, left, right);
            left = right+1;
            right = result.find(" ", left);
        }
        
        _reverseWords(result, left, result.size());
        return result;
    }
    
    void _reverseWords(string& s, int left, int right){
        char tmp;
        right --;
        while(left < right){
            tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }
};

// https://leetcode.com/problems/reverse-words-in-a-string-iii/description/
// #String #Find #Reverse