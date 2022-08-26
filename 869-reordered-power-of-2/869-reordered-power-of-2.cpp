class Solution {
public:
    
    bool isPowerofTwo(int n)
    {
        
         /*if(n==1)
        {
             cout<<n<<endl;
            return true;
        }
        
        if(n<1)
        {
            return false;
        }
        
        cout<<n<<endl;
        
        return n%2 && isPowerofTwo(n/2); */
        
        return (n&(n-1))==0;
    }
    
    bool permutations(string str,int left,int right)
    {
        if(left>right)
        {
            return false;
        }
        
        if(left==right)
        {
            char ch = str[0];
            
            if(ch != '0' && isPowerofTwo(stoi(str)))
            {
                   return true; 
            }
            else
            {
                return false;
            }
        }
        
        bool flag;
        
        for(int i=left;i<=right;i++)
        {
            swap(str[i],str[left]);
            flag = permutations(str,left+1,right);
            
            if(flag)
            {
                return true;
            }
            
            swap(str[left],str[i]);
        }
        
        return flag;
    }
    
    
    bool reorderedPowerOf2(int n) {
        
        if(n==1 || n==2)
        {
            return true;
        }
        
        string str = to_string(n);
        
        int size = str.size();
        
        if(permutations(str,0,size-1))
        {
            return true;
        }
        
        return false;
        
    }
};