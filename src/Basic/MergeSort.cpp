vector<int> sortArray(vector<int>& nums) {
    // Mergesort
    vector<int> result = nums;
    mergesort(result, 0, nums.size()-1);
    return result;
}

void mergesort(vector<int>& nums, int left, int right)
{
    if (left >= right)
        return;
    
    int mid = (left + right)/2;
    
    mergesort(nums, left, mid);
    mergesort(nums, mid+1, right);
    
    merge(nums, left, mid, right);
}

void merge(vector<int>& nums, int left, int mid, int right)
{
    vector<int> tmp(right - left + 1, 0);
    
    int i = left;
    int j = mid + 1;
    int k = 0;
    
    while(i <= mid && j <= right)
    {
        if(nums[i] <= nums[j])
            tmp[k++] = nums[i++];
        else
            tmp[k++] = nums[j++];
    }
    while(i <= mid)
        tmp[k++] = nums[i++];
    
    while(j <= right)
        tmp[k++] = nums[j++];
    
    for(i=0; i<k; i++)
        nums[left + i] = tmp[i];
}