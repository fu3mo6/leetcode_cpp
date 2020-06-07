class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int ret = 0;
        
        while(left <= right){            
            if(height[left] > height[right]){
                ret = max(ret, height[right] * (right - left));
                right --;
            }
            else {
                ret = max(ret, height[left] * (right - left));
                left ++;                
            }                
        }
        return ret;
    }
};

// https://leetcode.com/problems/container-with-most-water/description/