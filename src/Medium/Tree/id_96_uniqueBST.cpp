class Solution {
public:
    int numTrees(int n) {
        if(n==1)
            return 1;
        vector<int> result(n+1 , 0);
        result[0] = 1;
        result[1] = 1;
        for(int i=2; i<=n; i++){
            result[i] = 0;
            for(int j=1; j<=i; j++){
                result[i] += result[j-1] * result[i-j];
            }
        }
        return result[n];
    }
};

// https://leetcode.com/problems/unique-binary-search-trees/description/