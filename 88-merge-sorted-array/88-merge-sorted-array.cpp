class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        int ind1 = m-1;
        int ind2 = n-1;
        int ind = m+n-1;
        
        while(ind1 >= 0 && ind2 >= 0)
        {
            if(nums1[ind1] > nums2[ind2])
            {
                nums1[ind] = nums1[ind1];
                ind1--;
                ind--;
            }
            else
            {
                nums1[ind] = nums2[ind2];
                ind2--;
                ind--;
            }
        }
        
        //below 2 conditions are for example 1 and example 2
        while(ind1 >= 0 && ind >= 0)
        {
            nums1[ind] = nums1[ind1];
            ind1--;
            ind--;
        }
        
        
        while(ind2 >= 0 && ind >= 0)
        {
            nums1[ind] = nums2[ind2];
             ind--;
             ind2--;
        }
    }
};