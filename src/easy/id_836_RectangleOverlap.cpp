class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        // y overlap and x overlap
        // A or B < A + B
                
        bool x_over = max(rec1[2], rec2[2]) - min(rec1[0], rec2[0]) - (rec1[2]-rec1[0]+rec2[2]-rec2[0]) < 0;
        bool y_over = max(rec1[3], rec2[3]) - min(rec1[1], rec2[1]) - (rec1[3]-rec1[1]+rec2[3]-rec2[1]) < 0;
        
        return (x_over && y_over);
    }
};

// https://leetcode.com/problems/rectangle-overlap/description/
// #math