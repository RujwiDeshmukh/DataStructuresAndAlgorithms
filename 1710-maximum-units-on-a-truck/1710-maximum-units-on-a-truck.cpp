class Solution {
public:
    
    bool static sorter(vector<int>&a, vector<int>&b)
    {
        if(a[1]==b[1])
        {
            if(a[0] > b[0])
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        
        else if(a[1]>b[1])
        {
            return true;
        }
        
        return false;   
    }
    
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        
        int n = boxTypes.size();
        int ans=0;
        
        sort(boxTypes.begin(), boxTypes.end(),sorter);
        
        for(int i=0;i<n;i++)
        {
            if(truckSize >= boxTypes[i][0])
            {
                ans += boxTypes[i][0]*boxTypes[i][1];
                truckSize -= boxTypes[i][0];
            }
            else
            {
                ans += boxTypes[i][1]*truckSize;
                truckSize=0;
                break;
            }
        }
        
        return ans;
    }
};