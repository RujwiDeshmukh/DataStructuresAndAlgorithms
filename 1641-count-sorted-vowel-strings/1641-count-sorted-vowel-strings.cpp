class Solution {
public:
    
    
    void countStrings(int idx,int length,int n,int &count)
    {
        length++;
        
          if(length==n)
          {
              count++;
              return ;
          }
        
         
        for(int i=idx;i<5;i++)
        {
            countStrings(i,length,n,count);
        }
    }
    
    int countVowelStrings(int n) {
        
        int count=0;
        
        for(int i=0;i<5;i++)
        {
            countStrings(i,0,n,count);
        }
        
        return count;
        
    }
};