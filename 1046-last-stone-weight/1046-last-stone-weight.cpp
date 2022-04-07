class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        int n = stones.size();
        sort(stones.begin(),stones.end(),greater<int>());
        
        while(n > 1)
        {
            int first = stones[0];
            int second = stones[1];
            //removing 1st 2 elements from the stones array list
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            
            if(first != second)
            {
                stones.push_back(first-second);
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