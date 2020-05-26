class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0); // 5,10,20
        
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                change[0]++;
            }
            else if(bills[i] == 10 && change[0] > 0){
                change[0]--;
                change[1]++;
            }
            else if(bills[i] == 20 && change[0] > 0 && change[1] > 0){
                change[0]--;
                change[1]--;
                change[2]++;
            }
            else if(bills[i] == 20 && change[0] > 2){
                change[0] -= 3;
                change[2] ++;
            }
            else
                return false;            
        }
        return true;
    }
};

// https://leetcode.com/problems/lemonade-change/description/
// #Application