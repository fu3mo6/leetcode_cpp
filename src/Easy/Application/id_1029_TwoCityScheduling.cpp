class Solution {
public:
    static bool comp(vector<int>& A, vector<int>& B){
        return ((A[0]-A[1])-(B[0]-B[1])<0);
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), comp);
        
        int result = 0;
        int N = costs.size()/2;
        for(int i=0; i<costs.size(); i++){
            result += costs[i][i/N];
        }
        return result;
    }
};

// https://leetcode.com/problems/two-city-scheduling/description/
// #Greedy #Sort