class Solution {
public:
    
   // https://leetcode.com/discuss/general-discussion/547798/static-comparator-function-for-sort-reasons-as-to-why-c
    
 //   https://leetcode.com/problems/the-number-of-weak-characters-in-the-game/discuss/1445186/EASY-C%2B%2B-solution-with-great-explanation-and-comments-(nlogn)-sorting
    
    
    static bool comp(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
        {
            //condition for ascending order
            return a[1] < b[1];
        }
        
        //condition for descending order
        return a[0] > b[0];
    }
    
    
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        
        sort(properties.begin(),properties.end(),comp);
        int ans=0;
        int maxi=INT_MIN;
        
     /*   for(int i=0;i<properties.size();i++)
        {
            cout<<properties[i][0]<<" "<<properties[i][1]<<endl;
        }
        */
        
        for(int i=0;i<properties.size();i++)
        {
           if(properties[i][1] < maxi)
           {
               ans++;
           }
            
           maxi = max(maxi,properties[i][1]);
        }
        
        return ans;
    }
};