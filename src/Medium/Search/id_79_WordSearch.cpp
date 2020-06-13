class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(search_word(board, i, j, 0, word))
                    return true;
            }
        }
        return false;        
    }
    
    bool search_word(vector<vector<char>>& board, int x, int y, int round, string word){
        if(x<0 || y<0 || x>=board.size() || y>=board[x].size())
            return false;
            
        if(board[x][y]!=word[round])
            return false;        
        
        if(round == word.length()-1)
            return true;
        
        char tmp;
        tmp = board[x][y];
        board[x][y] = '.';
        
        bool result = search_word(board, x+1, y, round+1, word);
        if(!result)
            result  = search_word(board, x, y+1, round+1, word);
        if(!result)
            result  = search_word(board, x-1, y, round+1, word);
        if(!result)
            result  = search_word(board, x, y-1, round+1, word);
        
        board[x][y] = tmp;
        return result;        
    }
};

// https://leetcode.com/problems/word-search/description/
// #DFS