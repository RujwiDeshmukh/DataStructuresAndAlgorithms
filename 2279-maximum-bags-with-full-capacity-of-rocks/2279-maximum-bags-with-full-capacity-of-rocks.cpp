class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        
        int size = rocks.size();
        int cnt=0;
        
        for(int i=0;i<size;i++)
        {
            rocks[i] = capacity[i]-rocks[i];
        }
        
        sort(rocks.begin(),rocks.end());
        
        for(int i=0;i<size;i++)
        {
            if(additionalRocks-rocks[i] >= 0)
            {
                additionalRocks -= rocks[i];
                cnt++;
            }
        }
        
        //https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/discuss/2061949/Greedy-oror-Intuition-oror-O(1)-Space-oror-(C%2B%2BJava)
        return cnt;
    }
};