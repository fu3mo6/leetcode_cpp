class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        if(A.size()==1)
            return true;
        
        int judge = 0;
        
        for(int i=1; i<A.size(); i++){
            if(A[i] > A[i-1]){
                if(judge < 0)
                    return false;
                else
                    judge = 1;            
            }            
            else if(A[i] < A[i-1]){
                if(judge > 0)
                    return false;
                else
                    judge = -1;            
            }                
        }
        
        return true;
    }
};

// https://leetcode.com/problems/monotonic-array/description/
// O(n)