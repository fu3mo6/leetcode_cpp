class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<int> check;
        
        for(int i=0; i<9; i++)
        {
            check.assign(10,0);
            for(int j=0; j<9; j++){
                if(!isValid(check, board[i][j]))
                    return false;
            }
        }
        
        for(int i=0; i<9; i++)
        {
            check.assign(10,0);
            for(int j=0; j<9; j++){
                if(!isValid(check, board[j][i]))
                    return false;
            }
        }
        
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                check.assign(10,0);
                
                if(!isValid(check, board[i*3][j*3]))
                    return false;
                if(!isValid(check, board[i*3+1][j*3]))
                    return false;
                if(!isValid(check, board[i*3+2][j*3]))
                    return false;
                if(!isValid(check, board[i*3][j*3+1]))
                    return false;
                if(!isValid(check, board[i*3+1][j*3+1]))
                    return false;
                if(!isValid(check, board[i*3+2][j*3+1]))
                    return false;
                if(!isValid(check, board[i*3][j*3+2]))
                    return false;
                if(!isValid(check, board[i*3+1][j*3+2]))
                    return false;
                if(!isValid(check, board[i*3+2][j*3+2]))
                    return false;
            }
        }
        return true;
    }
    
    bool isValid(vector<int>& check, char target){
        if(target == '.')
            return true;
        
        if(check[target-'0'] == 0){
            check[target-'0'] = 1;
            return true;
        }
        else {
            return false;
        }
    }
};

// https://leetcode.com/problems/valid-sudoku/description/
// #Application