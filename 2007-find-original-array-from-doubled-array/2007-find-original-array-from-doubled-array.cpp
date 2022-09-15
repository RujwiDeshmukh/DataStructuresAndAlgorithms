class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2==1)
        {
            return {};
        }
        vector<int>ans;      
        vector<int>uniqueNums;
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++) {  mp[changed[i]]++;  }
        
        //just to eliminate repeated elements from array
        //to decrease the sorting Time Complexity
        
        for(auto m : mp)   {  uniqueNums.push_back(m.first);   }
        
        sort(uniqueNums.begin(),uniqueNums.end());     
        
       for(auto num : uniqueNums)
       {
           if(mp[num] > mp[2*num]) {  return {}; };
           
           for(int i=0;i<mp[num];i++)
           {
               ans.push_back(num);
               mp[2*num]--;
           }
       }
        
        return ans;
        
        //https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/2577700/C%2B%2B-or-HashmapSorting(NlogN)-Approach
        
        //https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/1470959/JavaC%2B%2BPython-Match-from-the-Smallest-or-Biggest-100
        
        //https://leetcode.com/problems/find-original-array-from-doubled-array/discuss/2577514/LeetCode-The-Hard-Way-Explained-Line-By-Line
    }
};