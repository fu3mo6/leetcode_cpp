class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1.size() < num2.size())
            return multiply(num2, num1);
        
        string result;
        string zero = "";
        for(int i=num2.size()-1; i>=0; i--){
            result = plus(multiply_digit(num1, num2[i]-'0')+zero, result);
            zero += "0";            
        }
        
        return result;
    }
    
    string multiply_digit(string num1, int val){
        if(val == 0)
            return "0";
        if(val == 1)
            return num1;
        
        string result = num1;
        int i = num1.size()-1;
        int extra = 0;
        int tmp;
        
        while(i>=0){
            tmp = (num1[i]-'0')*val + extra;
            result[i] = tmp % 10 + '0';
            extra = tmp / 10;
            i--;
        }
        
        if(extra > 0)
            result = to_string(extra) + result;
        return result;        
    }
    string plus(string num1, string num2){
        if(num1.size() < num2.size())
            return plus(num2, num1);
        
        string result = num1;
        int i = num1.size()-1;
        int j = num2.size()-1;
        int extra_one = 0;
        int tmp;
        
        while(j>=0 || extra_one > 0){
            if(j < 0){
                if(i<0){
                    result = "0" + result;
                    i++;
                }
                tmp = (result[i]-'0') + extra_one;
                result[i] = tmp % 10 + '0';
                extra_one = tmp / 10;
                i--;
            }
            else {
                tmp = (result[i]-'0') + (num2[j]-'0') + extra_one;
                result[i] = tmp % 10 + '0';
                extra_one = tmp / 10;
                i--;
                j--;                
            }            
        }
        return result;        
    }
};

// https://leetcode.com/problems/multiply-strings/description/