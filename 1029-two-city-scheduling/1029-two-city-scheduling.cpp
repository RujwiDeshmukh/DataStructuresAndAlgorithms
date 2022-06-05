class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
           
        //https://leetcode.com/problems/two-city-scheduling/discuss/1881010/C%2B%2B-oror-Explained-oror-Easy-oror-Simple-and-Short-oror-Algorithm
        
        vector<int>diff;
        
        int minCost=0;
        
        for(int i=0;i<costs.size();i++)
        {
            minCost += costs[i][0];
            
            diff.push_back(costs[i][1]-costs[i][0]);
        }
        
        sort(diff.begin(),diff.end());
        
        for(int i=0;i<(costs.size())/2;i++)
        {
            minCost += diff[i];
        }
        
        return minCost;
    }
};