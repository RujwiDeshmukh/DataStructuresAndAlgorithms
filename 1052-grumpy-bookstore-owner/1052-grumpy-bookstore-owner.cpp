class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes)    {
        int satisfied=0;
          for(int i=0;i<grumpy.size();i++)
          {
              if(grumpy[i]==0)
              {
                  satisfied+= customers[i];
              }
          }
        
        cout<<satisfied<<endl;
        
        int start=0,end=0;
        int grumpy_satisfied=0;
        int additional_grumpy = 0;
        
        while(end < grumpy.size())
        {
            if(grumpy[end]==1)
            {
                grumpy_satisfied += customers[end];
            }
            
            if(end-start+1 < minutes)
            {
                end++;
                continue;
            }
            
            if(end-start+1 > minutes)
            {
                if(grumpy[start]==1)
                {
                    grumpy_satisfied -= customers[start];
                }
                start++;
            }
            
            additional_grumpy = max(additional_grumpy,grumpy_satisfied);
            end++;
        }
        
        int ans = additional_grumpy+satisfied;
        
        return ans;
    }
};