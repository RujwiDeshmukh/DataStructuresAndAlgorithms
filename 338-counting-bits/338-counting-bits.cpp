class Solution {
public:
    vector<int> countBits(int n) {
        
        vector<int>ans;
        
        //https://leetcode.com/problems/counting-bits/discuss/1808016/C%2B%2B-oror-Vectors-Only-oror-Easy-To-Understand-oror-Full-Explanation
        
        for(int i=0;i<=n;i++)
        {
            int sum=0;
            int num=i;
            
            while(num != 0)
            {
                sum += num%2;
                num = num/2;
            }
            
            ans.push_back(sum);
        }
        
        return ans;
    }
};