class Solution {
public:
    
    int numberOfSubstrings(string s) {
        //variable sliding window technique

        unordered_map<char,int>mp;
        int n = s.size();
        
        int end=0 , start=0;
        int total=0;
        
        while(end < s.size())
        {
            mp[s[end]]++;
            
            if(mp.size() < 3)
            {
                end++;
                continue;
            }
            
            while(mp.size() == 3)
            {
                 total+= (n-end);
                 mp[s[start]]--;
                 if(mp[s[start]]==0)
                 {
                     mp.erase(s[start]);
                 }
                start++;
            }
            
            end++;
        }
        
        return total;
        
        //https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/discuss/1353644/C%2B%2B-or-Easy-Concise-or-Sliding-Window
    }
};