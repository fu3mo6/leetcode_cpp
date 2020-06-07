class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        vector<string> next;
        vector<string> table = {"0","1","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        if(digits.size()==0)
            return result;
        
        string tmp;
        char add;
        
        result.push_back("");
        for(int i=0; i<digits.size(); i++){
            next = {};            
            for(int j=0; j<table[digits[i]-'0'].size(); j++){
                add = table[digits[i]-'0'][j];
                for(int k = 0; k < result.size(); k++){
                    next.push_back(result[k]+add);
                }
            }            
            swap(next, result);
        }
        
        return result;
    }
};

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/description/
// #softofDP #UseLessMemoryBySwap