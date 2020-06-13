/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        
        if(intervals.size()<=1)
            return intervals;
        
        quicksort_by_start(intervals, 0, intervals.size()-1);
        
        int i=0;
        while(i<intervals.size()-1){
            if(!merge_ifoverlap(intervals, i, i+1)){
                i ++;
            }
        }
                
        return intervals;
    }
    
    void quicksort_by_start(vector<Interval>& intervals, int left, int right){
        int nextpos;
        if(left < right){
            nextpos = partition(intervals, left, right);
            quicksort_by_start(intervals, left, nextpos-1);
            quicksort_by_start(intervals, nextpos+1, right);
        }
    }
    
    int partition(vector<Interval>& intervals, int left, int right){
        int key = intervals[right].start;
        int pos = left - 1;
        
        for(int i = left; i<right; i++){            
            if(intervals[i].start < key){
                pos++;
                swap(intervals[i], intervals[pos]);
            }
        }
        pos++;
        swap(intervals[pos], intervals[right]);        
        return pos;
    }
    
    bool merge_ifoverlap(vector<Interval>& intervals, int i, int j){
        
        // since sorted, i.start <= j.start, so we can use single if to judge for overlap        
        if(intervals[i].end < intervals[j].start)
            return false;

        intervals[i].end = max(intervals[i].end, intervals[j].end);        
        intervals.erase(intervals.begin()+j);
        return true;
    }
};

// https://leetcode.com/problems/merge-intervals/description/