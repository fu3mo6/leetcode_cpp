class Solution {
public:
    vector<vector<int>> generateMatrix(int n){
        
        vector<vector<int>> result(n, vector<int>(n,0));
        
        int left = 0, right = n-1;
        int value = 1;
        
        while(left <= right)
        {
            addOneCircle(result, value, left, right);
            left++;
            right--;
        }
        return result;
    }

    void addOneCircle(vector<vector<int>>& matrix, int& value, int left, int right)
    {
        int x = left, y=left;
        
        if(left == right){
            // single point
            matrix[x][y] = value++;
        }
        else{
            while(y < right){ // move right
                matrix[x][y] = value++;
                y++;
            }
            while(x < right){ // move down
                matrix[x][y] = value++;
                x++;
            }
            while(y > left){ // move left
                matrix[x][y] = value++;
                y--;
            }
            while(x > left){ // move up
                matrix[x][y] = value++;
                x--;
            }            
        }
    }
};

// https://leetcode.com/problems/spiral-matrix-ii/description/