class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
       
        vector<int>countA(7,0);
        vector<int>countB(7,0);
        vector<int>countSame(7,0);
        
        int n = tops.size();
        
        for(int i=0;i<n;i++)
        {
            countA[tops[i]]++;
            countB[bottoms[i]]++;
            
            if(tops[i] == bottoms[i])
            {
                countSame[tops[i]]++;
            }
        }
        
        for(int i=1;i<=6;i++)
        {
            if(countA[i]+countB[i]-countSame[i]==n)
            {
                return n-max(countA[i],countB[i]);
            }
        }
        
        return -1;
    }
};