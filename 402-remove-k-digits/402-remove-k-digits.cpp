class Solution {
public:
    string removeKdigits(string num, int k) {
       
        //we will choose the peak to remove it so
        //we will remove such k elements

        while(k > 0)
        {
            //for the increasing curve, once the decrease curve is detected
            //halt the loop
            int i=0;
            while(i+1< num.size() && num[i]<=num[i+1])
            {
                i++;
            }
            //here as we are stating from 1 index i.e. i=1 so
            //i will increment first so we have to erase i-1
            cout<<i<<endl;
            num.erase(i,1);
            k--;
        }
        
        //checking for the leading zeros
        
        
        int i=0;
        
        while(i<num.size()-1 && num[i]=='0')
        {
            i++;
        }
        //first arg is index and second one is length of number of zeros
        num.erase(0,i);
        
        return num=="" ? "0" : num;
    }
};