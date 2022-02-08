class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int ans=0;
        //here it is same as the one we do for conversion from binary to decimal
        //here we are multiplying as we want by 26 as we want to calculate the column
        //Numbers
        for(int i=0;i<columnTitle.size();i++)
        {
            int columnNo = (columnTitle[i]-'A'+1);
            ans = (26*ans)+ columnNo;
                
        }
        
        return ans;
    }
};