class UnionFind {
public:
    UnionFind(int n) {
        rank = vector<int>(n, 1);
        f.resize(n);
        for (int i = 0; i < n; ++i) f[i] = i;
    }
    
    int Find(int x) {
        if (x == f[x]) return x;
        else return f[x] = Find(f[x]);
    }
    
    void Union(int x, int y) {
        int fx = Find(x), fy = Find(y);
        if (fx == fy) return;
        if (rank[fx] > rank[fy]) swap(fx, fy);
        f[fx] = fy;
        if (rank[fx] == rank[fy]) rank[fy]++;
    }
    
private:
    vector<int> f, rank;
};

class Solution {
public:
    static bool comp(vector<int> &a, vector<int>& b)
    {
        return a[2]<b[2]; // sorted by weight
    }
    
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges)
    {
        vector<vector<int>> result(2, vector<int>());
        vector<vector<int>> sorted_edges = edges;
        
        // Add edge id
        for(int i=0; i<edges.size(); i++)
            sorted_edges[i].push_back(i);
        
        sort(sorted_edges.begin(), sorted_edges.end(), comp);
        
        unordered_set<int> base_MST;
        int base_weight = MST(n, edges, sorted_edges, &base_MST, -1, -1);
        int new_weight;
                
        for(int i=0; i<edges.size(); i++)
        {
            if(base_MST.count(i) == 0)
            {
                new_weight = MST(n, edges, sorted_edges, NULL, i, -1);
                if(new_weight == base_weight)
                    result[1].push_back(i); // pseudo-critical
            }
            else
            {
                new_weight = MST(n, edges, sorted_edges, NULL, -1, i);
                if(new_weight == base_weight)
                    result[1].push_back(i); // pseudo-critical
                else
                    result[0].push_back(i); // critical
            }
        }
        
        return result;
    }
    
    int MST(int n, vector<vector<int>>& edges, vector<vector<int>>& sorted_edges, 
            unordered_set<int> *result, int include, int exclude)
    {
        UnionFind uf(n);
        vector<int> curr;
        int weight = 0;
        
        if(include >= 0)
        {
            curr = edges[include];
            uf.Union(curr[0], curr[1]);
            weight += curr[2];
            if(result) result->insert(include);
        }
        
        for(int i=0; i<sorted_edges.size(); i++)
        {
            curr = sorted_edges[i];
            if(curr[3] == include || curr[3] == exclude)
                continue;
            
            if(uf.Find(curr[0]) == uf.Find(curr[1]))
                continue;
            
            uf.Union(curr[0], curr[1]);
            weight += curr[2];
            if(result) result->insert(curr[3]);
        }
        
        for (int i = 0; i < n; ++i) {
            if (uf.Find(i) != uf.Find(0)) return INT_MAX;
        }
        
        return weight;
    }
};

/*
Find base-MST

for each edge:
if in base-MST:
    move from edge list and find new-MST
    if weight(new-MST) > weight(base-MST)
        edge is critical
    else
        edge is pseudo-critical
else
    add to must-use and find new-MST
    if weight(new-MST) > weight(base-MST)
        edge is neither
    else
        edge is pseudo-critical
*/

// https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/description/