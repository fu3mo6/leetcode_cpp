class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& A) {
        vector<int> result;
        for(int i=0; i<A.size(); i++){
            while(1){
                if(A[A[i]-1] == A[i] || A[i] == i + 1)
                    break;
                swap(A[i], A[A[i]-1]);
            }
        }
        
        for(int i=0; i<A.size(); i++){
            if(A[i] != i+1)
                result.push_back(i+1);
        }
        
        return result;
    }
};

// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/description/
// #inplace