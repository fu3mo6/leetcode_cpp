class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if(time.size() == 0)
            return 0;
        
        vector<int> seconds(60, 0);
        for(int i=0; i<time.size(); i++){
            seconds[time[i]%60]++;
        }
        
        int result = 0;
        if(seconds[0] >= 2) result += seconds[0]*(seconds[0]-1)/2;
        if(seconds[30] >= 2) result += seconds[30]*(seconds[30]-1)/2;
        
        for(int i=1; i<=29; i++){
            result += seconds[i] * seconds[60-i];
        }
        
        return result;
    }
};

// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/description/
// #math #fixedsizebuf