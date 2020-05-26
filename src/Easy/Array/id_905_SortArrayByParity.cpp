class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left=0;
        int right=A.size()-1;
        
        while(left < right){
            while(A[left]%2==0 && left < A.size())
                left++;
            
            while(A[right]%2==1 && right > 0)
                right--;
            
            if(left>=right)
                break;
            
            swap(A[left], A[right]);
            left++;
            right--;            
        }
        
        return A;
    }
};

// https://leetcode.com/problems/sort-array-by-parity/description/
// O(n) #inplace