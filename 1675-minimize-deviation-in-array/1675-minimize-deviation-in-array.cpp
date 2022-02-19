class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        
        set<int>st;
        st.insert(nums.begin(),nums.end());
        //deviation is diff betn max and min element in array
        int min_dev = (*st.rbegin() - *st.begin());
        
        int val = *st.begin();
        //maximize odd
        while(val%2==1)
        {
            st.erase(val);
            st.insert(val*2);
            val = *st.begin();
            min_dev = min(min_dev, *st.rbegin()-val);
        }
        
        val = *st.rbegin();
          //minimize even
        while(val%2==0)
        {
            st.erase(val);
            st.insert(val/2);
            val = *st.rbegin();
            min_dev = min(min_dev, val-*st.begin());
        }
        
      return min_dev;
    }
};