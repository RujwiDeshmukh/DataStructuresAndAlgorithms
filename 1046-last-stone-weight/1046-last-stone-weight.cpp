class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        sort(stones.begin(),stones.end(),greater<int>());
        
        int n = stones.size();
        int i=0;
        
        while(n > 1)
        {
           int first = stones[0];
            int second = stones[1];
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            
            if(first!=second)
            {
             first = first-second;   
             stones.push_back(first);
            }
            
            sort(stones.begin(),stones.end(),greater<int>());
            n = stones.size();
        }
        
        if(stones.size()==0)
        {
            return 0;
        }
        
        return stones[0];
        
    }
};