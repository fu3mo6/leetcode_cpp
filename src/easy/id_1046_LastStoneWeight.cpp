class Solution {
public:
    int lastStoneWeight(vector<int>& A) {
        priority_queue<int> pq(begin(A), end(A));
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if (x > y) pq.push(x - y);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& A) {
        int maxima = INT_MIN;
        for(int i=0; i<A.size(); i++)
        {
            maxima = max(maxima, A[i]);
        }
        
        vector<int> bucket(maxima+1,0);
        for(int i=0; i<A.size(); i++)
            bucket[A[i]]++;
        
        int stone = 0, i = maxima;
        while(i>0)
        {
            if(bucket[i] == 0){
                i--;
                continue;
            }
            else if(stone == 0)
            {
                if(bucket[i]%2 == 1){
                    stone = i;
                }
                i--;
            }
            else {
                stone = stone - i;
                bucket[i] --;
                if(stone < i)
                {
                    bucket[stone]++;
                    stone = 0;
                }
            }
        }
        return stone;
    }
};

// https://leetcode.com/problems/last-stone-weight/description/
// #PriorityQueue #BucketSort