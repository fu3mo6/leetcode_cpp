class Solution {
public:
    int titleToNumber(string s) {
        int result = 0;
        int idx;
        int power;
        for(int i=0; i<s.size(); i++){
            idx = s[i]-'A'+1;
            power = pow(26, s.size()-i-1);
            result += idx * power;
        }
        return result;
    }
};

// https://leetcode.com/problems/excel-sheet-column-number/description/
// #Application #CharToInteger