class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        
        int i=0;
        int j=arr.size()-1;
        cout<<arr.size()<<endl;
        vector<int>v;
        
        while(i<j)
        {
            if(arr[i]+arr[j] == target)
            {
                v.push_back(i+1);
                v.push_back(j+1);
                return v;
            }
            else if(arr[i]+arr[j] < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        
        return v;
    }
};