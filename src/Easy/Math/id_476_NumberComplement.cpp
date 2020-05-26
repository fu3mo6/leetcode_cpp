class Solution {
public:
    int findComplement(int num) {        
        int mask = ~0; // 0xffff
        while (num & mask) 
            mask = mask << 1;
        
        mask = ~mask;
        return mask & ~num;
    }
};

// https://leetcode.com/problems/number-complement/description/
// #bitoperation