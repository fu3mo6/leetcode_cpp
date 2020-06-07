class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        
        int left = 0, right = arr.size()-1;
        vector<int> result(k,0);
        
        int median = arr[(arr.size()-1)/2];
        
        for(int i=0; i<k; i++){
            if(median - arr[left] > arr[right] - median)
            {
                result[i] = arr[left++];
            }
            else {
                result[i] = arr[right--];
            }
        }
        
        return result;
        
    }
};

// https://leetcode.com/problems/the-k-strongest-values-in-an-array/description/