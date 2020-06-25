class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        vector<int> result(rains.size(), 0);
        unordered_map<int, int> full_day;
        set<int> dry_days;
        
        int dry_id = 0;
        for(int i=0; i<rains.size(); i++)
        {
            
            if(rains[i] == 0)
            {
                result[i] = 1;
                dry_days.insert(i);
            }
            else
            {
                if(full_day.find(rains[i]) != full_day.end())
                {
                    auto it = dry_days.lower_bound(full_day[rains[i]]);
                    if(it == dry_days.end())
                        return {};
                    result[*it] = rains[i];
                    dry_days.erase(it);
                }
                full_day[rains[i]] = i;
                result[i] = -1;
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/avoid-flood-in-the-city/description/