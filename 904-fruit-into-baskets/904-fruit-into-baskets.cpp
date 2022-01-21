class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        //variable sliding window problem it is
        
        unordered_map<int,int>mp;
        int ans=0;
        int res=0;
        int start=0 , end=0;
        
       /* if(fruits.size()==1)
        {
            return 1;
        }
        */
        while(end < fruits.size())
        {   
            mp[fruits[end]]++;
        
            /*if(mp.size() < 2)
            {
                end++;
                continue;
            }*/
            
            /*[2,2,2,2,2,2,2,2]*/ /*it would give answer as 0 if we take exactly
                k distinct elements bt answer should be 8 */
            
            //problem statemnt is longest subarray with at most k distinct elements
            
            if(mp.size() <= 2)
            {
                //whenever a new fruit come
                 ans = end-start+1;
                res = max(ans,res);
            }
            
            
            while(mp.size() > 2)
            {
                mp[fruits[start]]--;
                
                if(mp[fruits[start]]==0)
                {
                    mp.erase(fruits[start]);
                }
                start++;
            }
            
            end++;
        }
        return res;
    }
};