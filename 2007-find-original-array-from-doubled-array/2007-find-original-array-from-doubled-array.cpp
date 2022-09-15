class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if(n%2==1)
        {
            return {};
        }
        vector<int>ans;
        sort(changed.begin(),changed.end());
        unordered_map<int,int>mp;
        
        for(int i=0;i<n;i++)
        {
            mp[changed[i]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(mp[changed[i]]==0) continue;
            if(mp[2*changed[i]]==0) return {};
            ans.push_back(changed[i]);
            mp[changed[i]]--;
            mp[2*changed[i]]--;
        }
        
        return ans;
    }
};