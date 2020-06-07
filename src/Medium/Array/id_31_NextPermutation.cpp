class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()<2)
            return;
        
        int i;
        for(i=nums.size()-1; i>0; i--){
            if(nums[i] > nums[i-1]){
                break;
            }
        }
        if(i==0){ // cannot find next. find smallest
            reverse(nums, 0, nums.size()-1);
        }
        else { // not in order at position i
            int j=nums.size()-1;
            while(j>=i){
                if(nums[j] > nums[i-1]){
                    break;
                }
                j--;
            }
            
            swap(nums[j], nums[i-1]);
            reverse(nums, i, nums.size()-1);
        }        
    }
    
    void reverse(vector<int>& nums, int left, int right){
        if(left >= right)
            return;
        for(int i=0; i<=(right-left)/2; i++){
            swap(nums[left+i], nums[right-i]);
        }
    }
};

/*
"swap and reverse"

****45321 -> ****51234
     i
swap 4&5, and reverse "4321"

****35421 -> ****45321 -> ****41235
    *i*
swap 3&4, and reverse "5321"

*/

// https://leetcode.com/problems/next-permutation/description/
// #Math