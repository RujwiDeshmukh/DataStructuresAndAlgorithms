class Solution {
public:
    int minSetSize(vector<int>& arr) {
        
        //https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/1319437/Simple-Solution-w-Explanation-or-Delete-Elements-by-Max-Frequency-or-O(N)-Beats-100
        
        unordered_map<int,int>mp;
        //rather than using multiset to sort elements in descending order use
        //max so that number with higher frequency will be at the top
        priority_queue<int>pq;
        
        for(auto num : arr)
        {
            mp[num]++;
        }
        
        for(auto m : mp)
        {
            int freq = m.second;
            pq.push(freq);
        }
        
        int deleted=0 , ans=0;
        
        while(!pq.empty())
        {
            deleted += pq.top();
            pq.pop();
            ans++;
            
            if(deleted >= (arr.size())/2)
            {
                return ans;
            }
        }
        
        return -1;
    }
};