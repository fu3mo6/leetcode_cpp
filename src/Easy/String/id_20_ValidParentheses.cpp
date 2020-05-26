class Solution {
public:
    bool isValid(string s) {
        stack<char> p_stack;
        
        for(int i=0; i<s.size(); i++){
            
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                p_stack.push(s[i]);
            }
            else {
                if(p_stack.empty())
                    return false;
                if(!isPair(p_stack.top(), s[i]))
                    return false;
                p_stack.pop();
            }
        }
        
        if(!p_stack.empty())
            return false;
        
        return true;
    }
    bool isPair(char c1, char c2){
        return (c1=='(' && c2==')') || (c1=='{' && c2=='}') || (c1=='[' && c2==']');
    }
};

// https://leetcode.com/problems/valid-parentheses/description/
// #stack
