class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix){
        vector<int> result;
        int row = matrix.size();
        if(row==0) return result;
        int col = matrix[0].size();
        if(col==0) return result;

        int x1 = 0, y1 = 0, x2 = col-1, y2 = row-1;
                
        while(x1 <= x2 && y1 <= y2)
        {
            addOneCircle(matrix, result, x1, y1, x2, y2);
            x1++;
            y1++;
            x2--;
            y2--;
        }
        
        return result;
    }

    void addOneCircle(vector<vector<int>>& matrix, vector<int>& result,
                      int x1, int y1, int x2, int y2)
    {
        int x = x1;
        int y = y1;
        
        if(x1 == x2 && y1 == y2){
            result.push_back(matrix[y][x]);
            return;
        }
        else if(x1 == x2)
        {
            while(y <= y2){ // move down
                result.push_back(matrix[y][x]);
                y++;
            }
        }
        else if(y1 == y2)
        {
            while(x <= x2){ // move right
                result.push_back(matrix[y][x]);
                x++;
            }
        }
        else {
            while(x < x2){ // move right
                result.push_back(matrix[y][x]);
                x++;
            }
            while(y < y2){ // move down
                result.push_back(matrix[y][x]);
                y++;
            }
            while(x > x1 && y2 > y1){ // move left
                result.push_back(matrix[y][x]);
                x--;
            }
            while(y > y1 && x2 > x1 ){ // move up
                result.push_back(matrix[y][x]);
                y--;
            }
        }
    }
};

// https://leetcode.com/problems/spiral-matrix/description/