class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& num) {
        vector<vector<int> > res;

        std::sort(num.begin(), num.end());

        for (int i = 0; i < num.size(); i++) {
            
            if(num[i]>0)
                break;
            
            // Find all j,k such that num[i] + num[j] + num[k] = 0, i < j < k
            int target = -1 * num[i];
            int front = i + 1;
            int back = num.size() - 1;

            while (front < back) {

                int sum = num[front] + num[back];

                // Finding answer which start from number num[i]
                if (sum < target)
                    front++;

                else if (sum > target)
                    back--;

                else {
                    vector<int> triplet(3, 0);
                    triplet[0] = num[i];
                    triplet[1] = num[front];
                    triplet[2] = num[back];
                    res.push_back(triplet);

                    // move front to next non-equal number: prevent duplicate
                    while (front < back && num[front] == triplet[1]) front++;

                    // move back to next non-equal number: prevent duplicate
                    while (front < back && num[back] == triplet[2]) back--;
                }

            }

            // move i to next non-equal number
            while (i + 1 < num.size() && num[i + 1] == num[i]) 
                i++;

        }

        return res;
    }
};

// https://leetcode.com/problems/3sum/description/
// #Array #SortArrayFirst