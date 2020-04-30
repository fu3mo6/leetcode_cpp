class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i=0, j=0;
        while(j < n){
            if(i==m+j){
                nums1[i] = nums2[j];
                i++;
                j++;
            }
            else if(nums1[i] > nums2[j]){
                nums1.insert(nums1.begin()+i, nums2[j]);
                nums1.pop_back();
                i++;
                j++;
            }
            else {
                i++;
            }
        }
    }
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = m-1;
        int j = n-1;
        int k = m + n - 1;
        
        while(j >= 0)
        {
            if(i < 0) {
                nums1[k--] = nums2[j--];
            }
            else {
                if(nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                }
                else {
                    nums1[k--] = nums2[j--];
                }
            }
        }
    }
};

// https://leetcode.com/problems/merge-sorted-array/description/
// #SortedArray #inplace