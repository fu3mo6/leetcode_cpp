class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<string> tmp_vec;
        unordered_map<string, int> idx_map;
        
        string tmp_str;
        for(int i=0; i<strs.size(); i++){
            tmp_str = strs[i];
            sort(tmp_str.begin(), tmp_str.end());
            
            if(idx_map.count(tmp_str)==0){
                tmp_vec.clear();
                tmp_vec.push_back(strs[i]);
                idx_map[tmp_str]=result.size();
                result.push_back(tmp_vec);
            }
            else{
                result[idx_map[tmp_str]].push_back(strs[i]);
            }
        }
        
        return result;
    }
};

// https://leetcode.com/problems/group-anagrams/description/
// #unordered_map