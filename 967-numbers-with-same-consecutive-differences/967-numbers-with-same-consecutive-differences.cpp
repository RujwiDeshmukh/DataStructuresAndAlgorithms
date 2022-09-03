class Solution {
public:
    //https://leetcode.com/problems/numbers-with-same-consecutive-differences/discuss/2521519/LeetCode-The-Hard-Way-Easy-BFS-100-Explained-Line-By-Line
    vector<int> numsSameConsecDiff(int n, int k) {
        
       // queue<int>q {1,2,3,4,5,6,7,8,9};
        queue<int>q;
        q.push(1);q.push(2);q.push(3);q.push(4);q.push(5);q.push(6);
        q.push(7);q.push(8);q.push(9);
        
        while(n > 1)  //the loop will run only for n-1 times , as already 1 digit 
            //there in queue
        {
            int size=q.size();
            
            for(int i=0;i<size;i++)
            {
                int num = q.front();
                q.pop();
                
                int last_dig = num%10;
                
                for(int i=0;i<10;i++)
                {
                    if(abs(last_dig-i)==k)
                    {
                        q.push(num*10+i);
                    }
                }
            }
            
            n--;
        }
        
       // vector<int>ans {q.begin(),q.end()};
        vector<int>ans;
        
        while(!q.empty())
        {
            int num = q.front();
            q.pop();
            
            ans.push_back(num);
        }
        
        return ans;
    }
};