vector<int> sortArray(vector<int>& nums) {
    // Quicksort
    vector<int> result = nums;
    quicksort(result, 0, nums.size()-1);
    return result;
}

void quicksort(vector<int>& nums, int left, int right)
{
    int pos;
    if(left < right)
    {
        pos = partition(nums, left, right);
        quicksort(nums, left, pos-1);
        quicksort(nums, pos+1, right);
    }
}

int partition(vector<int>& nums, int left, int right)
{
    int key = nums[right];
    int pos = left - 1;
    
    for(int i = left; i < right; i++){
        if(nums[i] < key)
        {
            pos++;
            swap(nums[i], nums[pos]);
        }
    }
    pos++;
    swap(nums[pos], nums[right]);
    return pos;
}

// https://leetcode.com/problems/sort-an-array/description/