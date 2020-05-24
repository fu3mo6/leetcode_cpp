class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.size()!= B.size())
            return false;
        
        string dup = B+B;
        if(dup.find(A) == string::npos)
            return false;
        else
            return true;
    }
};

// https://leetcode.com/problems/rotate-string/description/
// #DuplicateTechnique